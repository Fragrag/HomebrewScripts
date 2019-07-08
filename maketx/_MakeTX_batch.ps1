Write-Output $PSScriptRoot

Get-ChildItem -Recurse $PSScriptRoot |
ForEach-Object {
    $file = $_.FullName
    $file_tx = ($_.BaseName + '.tx')
    $file_d = (Get-ItemProperty -Path $file -Name LastWriteTime).lastwritetime
    $file_tx_d = (Get-ItemProperty -Path $file_tx -Name LastWriteTime).lastwritetime

    if (Test-Path $file_tx) {

        if ($file_writetime -gt $file_tx_writetime) {
            Write-Output "Tx file was found and is older than the non-txt file!"
        }
        else {
            Write-Output "Tx file was found and is newer than the non-tx file!"
        }
    }

    else {
    Write-Output "No tx file was found!"
    }
}