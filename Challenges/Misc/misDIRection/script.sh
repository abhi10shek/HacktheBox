cat secret2 | sort -g | cut -d ":" -f2 | tr -d '\n'| base64 -d;echo
