import os;
path=input("")
info = "output = 'Document: {}'" # Keep the output for later debug
print(info.format(path))
exec(info.format(path)) # This is how you do string formatting, right?