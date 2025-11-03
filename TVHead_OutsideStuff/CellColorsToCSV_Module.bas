Attribute VB_Name = "Module1"
Sub CellColorsToCSV()
    ' --- Variable declarations ---
    Dim ws As Worksheet        ' Worksheet object representing the active sheet
    Dim cell As Range          ' Single cell within a range
    Dim rowRange As Range      ' Represents a row within the used range
    Dim colorDecimal As Long   ' Stores the decimal value of the cell's interior color
    Dim colorRGB As String     ' Stores the RGB string representation of a color (e.g., "255,0,0")
    Dim savePath As String     ' Path where the CSV file will be saved
    Dim fileName As String     ' Name of the CSV file (based on sheet name)
    Dim fullPath As String     ' Full path + file name for saving the CSV
    Dim fileNum As Integer     ' File number used for opening/writing the CSV
    Dim lineText As String     ' Stores the text of a row for writing into the CSV

    Dim cellText As String     ' Temporary variable storing the RGB string for the current cell

    ' --- Set the active sheet as the working worksheet ---
    Set ws = ActiveSheet

    ' === Loop through all cells in the used range to write RGB values ===
    For Each cell In ws.UsedRange
        ' Check if the cell has a fill color
        If cell.Interior.ColorIndex <> xlColorIndexNone Then
            ' Cell has a color ? convert Interior.Color decimal into R,G,B components
            colorDecimal = cell.Interior.Color
            colorRGB = colorDecimal Mod 256 & "," & (colorDecimal \ 256) Mod 256 & "," & (colorDecimal \ 65536) Mod 256
            
            ' Store the RGB string as text for later use
            cellText = CStr(colorDecimal Mod 256 & "," & (colorDecimal \ 256) Mod 256 & "," & (colorDecimal \ 65536) Mod 256)

        Else
            ' Cell has no fill ? write a placeholder value (black: "0,0,0")
            cell.Value = "0,0,0"
        End If

        ' Append the cell's RGB string to lineText with a semicolon separator
        lineText = lineText & cellText & ";"
    Next cell

    ' === Define CSV file save path and name ===
    savePath = "C:\Users\mimil\OneDrive - Collège de Maisonneuve\Cegep\SESSION_5\Tech\Perso\TVHead\TVHead_Draw\data\"
    fileName = ws.Name & ".csv"
    fullPath = savePath & fileName

    ' === Open the CSV file for writing ===
    fileNum = FreeFile                   ' Get a free file number for writing
    Open fullPath For Output As #fileNum  ' Open the file at fullPath for output
    
    
            ' Remove trailing semicolon at the end of the line
        If Right(lineText, 1) = ";" Then lineText = Left(lineText, Len(lineText) - 1)

        ' Write the completed line into the CSV file
        Print #fileNum, lineText

    ' === Close the CSV file after writing ===
    Close #fileNum

    ' === Notify the user that the CSV has been saved ===
    MsgBox "Sheet saved as " & fileName & " at:" & vbCrLf & fullPath, vbInformation, "Export complete"
End Sub

