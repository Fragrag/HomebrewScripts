# https://blogs.technet.microsoft.com/heyscriptingguy/2014/02/06/use-powershell-to-find-metadata-from-photograph-files/


$videoMetadata = Get-FileMetaData -folder (Get-childitem \\haryonas\media\video -Recurse -Directory).FullName

