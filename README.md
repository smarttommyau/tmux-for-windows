# Tmux for windows using wsl support

# Pre-request
- WSL

# Setup WSL

Install a new distro, alpine is recommended.\
Follow the basic instruction on installing it.\
Then install tmux.\
Alpine : apk update&&apk add tmux\
Debian/Ubuntu: apt install tmux

Add new file ~/.profile with this code to automatically run powershell in tmux sessions
```
if [ -n "$TMUX" ]; then
        pwsh.exe
fi
```
# Installation
## Download our program
[Download](https://github.com/smarttommyau/tmux-for-windows/releases/tag/Release)
## setup our program
Add the path you download our program to environment path.
## setup config
Add or edit file tmux.conf on the same folder of our program.
```
distro: alpine //your distro name
```
# Enjoy
