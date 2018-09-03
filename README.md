libotp-nametags
===========
This repository contains ready-to-use nametag (and margins) code reverse-engineered from libotp.dll.

Very few modifications have been made; most of the code was reverse engineered as-is. Consequently, it works almost exactly as it used to work on Toontown Online and Pirates Online. This means that core features, namely dynamic scaling and click regions, are fully implemented and operational. However, there's no support for widescreen margins, for example.

### Usage ###
If you're using this within a Toontown or POTCO project, just import the classes from `libotp`. Make sure that you've removed your previous implementation of nametags (for instance, you may need to remove `nametag.destroy()` calls).

### Screenshots ###
![Toontown - Toontown Central](https://cdn.discordapp.com/attachments/458393869659275264/486282006221553665/ttoff-screenshot-Mon-Sep-03-17-10-51-2018-29245.jpg)
![Toontown - Cashbot HQ](https://user-images.githubusercontent.com/6625888/45002043-174c2480-afa9-11e8-8b37-9ec367c122e5.jpg)
![Toontown - Lawbot HQ](https://user-images.githubusercontent.com/6625888/45002029-faafec80-afa8-11e8-9467-7478c583428a.jpg)
![Toontown - Oak Street](https://user-images.githubusercontent.com/6625888/45002034-fdaadd00-afa8-11e8-9d5e-90439d83b014.jpg)
![POTCO - Land](https://user-images.githubusercontent.com/6625888/45002016-e966e000-afa8-11e8-9461-7c71c003af06.jpg)
![POTCO - Sea](https://user-images.githubusercontent.com/6625888/45002021-ecfa6700-afa8-11e8-8ad8-357122b9113f.jpg)


### Contributing ###
We welcome all potential contributors.
