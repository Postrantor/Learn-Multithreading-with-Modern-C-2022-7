mkdir image
mv *.jpg .\image\
ffmpeg -i .\video.vtt .\video.srt
python .\str2note.py
