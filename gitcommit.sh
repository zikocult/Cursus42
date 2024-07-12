#!/bin/bash

read -p "Te parece correcto ir al repositorio $1? (y/n): " RESP
if [ "$RESP" == "y" ]; then
	cd $1
	git add .
	read -p "Descripción del commit: " DESC
	git commit -m "$DESC"
	git push origin HEAD
else
	exit 0
fi
