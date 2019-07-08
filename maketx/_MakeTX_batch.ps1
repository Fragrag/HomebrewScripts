Write-Output $PSScriptRoot

Get-ChildItem -Recurse $PSScriptRoot |
ForEach-Object {
    $file = $_.FullName
    $file_tx = ($_.DirectoryName + '\\' + $_.BaseName + '.tx')
    $file_d = (Get-ItemProperty -Path $file -Name LastWriteTime).lastwritetime
    $file_tx_d = (Get-ItemProperty -Path $file_tx -Name LastWriteTime).lastwritetime
    # Write-Output $file
    # Write-Output $file_tx
    # Write-Output $file_d
    # Write-Output $file_tx_d


    if (Test-Path $file_tx) {

        if ($file_writetime -gt $file_tx_writetime) {
            # & "C:\ProgramData\Autodesk\ApplicationPlugins\MAXtoA\maketx.exe -v -u --oiio $original -o $txfile"
            & "C:\solidangle\mtoadeploy\2017\bin\maketx.exe $original -o $txfile"

        }
        else {
            Write-Output "Tx file was found and is newer than the non-tx file!"
        }
    }

    else {
        # & "C:\ProgramData\Autodesk\ApplicationPlugins\MAXtoA\maketx.exe -v -u --oiio $original -o $txfile"
        & "C:\solidangle\mtoadeploy\2017\bin\maketx.exe $original -o $txfile"

    }
}