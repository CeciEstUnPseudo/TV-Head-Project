
// Client-side button handling: prevent full-page navigation and use fetch
document.addEventListener('DOMContentLoaded', function() {
  // Keep track of recent user selection to avoid server polling overriding it immediately
  let lastUserSelectTs = 0;
  const USER_SELECTION_TTL_MS = 5000; // prefer user selection for 5s after click

  function applySelectionToUI(selection) {
    // afficher dans l'élément HTML textuel en haut de page:
    if (selection) document.getElementById("etat-led").innerText = selection;

    // Trouver le bouton qui correspond et changer son style
    const boutons = document.querySelectorAll("button#Bouton");
    boutons.forEach((bouton) => {
      if (bouton.getAttribute("data") === selection) {
        bouton.classList.add("actif");
        bouton.classList.remove("inactif");
      } else {
        bouton.classList.remove("actif");
        bouton.classList.add("inactif");
      }
    });
  }

  // Restore persisted selection (if any)
  const persisted = localStorage.getItem('tvhead_selected');
  if (persisted) {
    applySelectionToUI(persisted);
  }

  // Intercept anchor clicks that point to /bouton* and use fetch instead of full navigation
  document.querySelectorAll('a[href^="/bouton"]').forEach((link) => {
    link.addEventListener('click', function(evt) {
      evt.preventDefault();
      const url = this.getAttribute('href');
      // Optional: visual feedback while request in flight
      const btn = this.querySelector('button#Bouton');
      if (btn) btn.classList.add('loading');

      fetch(url, { method: 'GET' })
        .then((res) => res.text())
        .then((text) => {
          // text may be the server response (index.html). We store the data attribute from the button as selection
          const selection = btn ? btn.getAttribute('data') : null;
          if (selection) {
            localStorage.setItem('tvhead_selected', selection);
            lastUserSelectTs = Date.now();
            applySelectionToUI(selection);
          }
        })
        .catch((err) => console.error('Fetch error', err))
        .finally(() => { if (btn) btn.classList.remove('loading'); });
    });
  });

  // Recevoir de l'info de l'ESP32 (polling)
  function actualiserEtatLED() {
    const maPromesse = fetch("/activeFace");
    maPromesse
    .then((maReponse) => maReponse.text())
    .then((mesData) => {
      // If user recently selected something, prefer that for a short TTL to avoid immediate override
      if (Date.now() - lastUserSelectTs < USER_SELECTION_TTL_MS) return;

      // Apply server state
      applySelectionToUI(mesData);
      // Keep in localStorage too so the choice persists across reloads
      localStorage.setItem('tvhead_selected', mesData);
    })
    .catch((err) => console.error('Error polling activeFace', err));
  }

  // Poll every 500ms (was 100ms, which is high; reduce to 500ms)
  setInterval(actualiserEtatLED, 500);
  // Also call once on load
  actualiserEtatLED();
});
  
