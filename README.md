libotp-nametags
===========
This repository contains ready-to-use nametag (and margins) code reverse-engineered from libotp.dll.

Very few modifications have been made; most of the code was reverse engineered as-is. Consequently, it works almost exactly as it used to work on Toontown Online and Pirates Online. This means that core features, namely dynamic scaling and click regions, are fully implemented and operational. However, there's no support for widescreen margins, for example.

### Usage ###
If you're using this within a Toontown or POTCO project, just import the classes from `libotp`. Make sure that you've removed your previous implementation of nametags (for instance, you may need to remove `nametag.destroy()` calls).

### Contributing ###
We welcome all potential contributors.
