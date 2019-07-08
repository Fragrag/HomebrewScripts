Write-Output $PSScriptRoot

Get-ChildItem -Recurse $PSScriptRoot |
ForEach-Object {
    $file = $_.FullName
    $file_tx = ($_.DirectoryName + '\' + $_.BaseName + '.tx')
    $arg1 = '-v'
    $arg2 = '-u'
    $arg3 = '--oiio'
    $arg4 = '-o'        
    $cmd = "C:\solidangle\mtoadeploy\2017\bin\maketx.exe"

    if (Test-Path $file_tx) {
    $file_d = (Get-ItemProperty -Path $file -Name LastWriteTime).lastwritetime
    $file_tx_d = (Get-ItemProperty -Path $file_tx -Name LastWriteTime).lastwritetime
        if ($file_d -gt $file_tx_d) {
            & $cmd $arg1 $arg2 $arg3 $file $arg4 $file_tx

        }
        else {
            Write-Output "Tx file was found and is newer than the non-tx file!"
        }
    }

    else {
        & $cmd $arg1 $arg2 $arg3 $file $arg4 $file_tx

    }
}