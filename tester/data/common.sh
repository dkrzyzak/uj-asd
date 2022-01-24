Error(){
	echo -e "\033[91mError:   \033[93m${1}\033[m"
	exit 1
}

Success() {
	echo -e "\033[92mSuccess: \033[93m${1}\033[m"
}

Prepare() {
	Set="${0#*_}" 
	Set="${Set%.*}"
	clear
	echo -e "\033[95m[[ ${Set} ]]\033[m"
}

FindLua() {
	if ! command -v lua &> /dev/null; then
		Error "lua could not be found"
	elif lua -v | grep -q "^Lua 5.2"; then
		Tester="lua data/tester_lua52.luac"
	elif lua -v | grep -q "^Lua 5.3"; then
		Tester="lua data/tester_lua53.luac"
	elif lua -v | grep -q "^Lua 5.4"; then
		Tester="lua data/tester_lua54.luac"
	else
		lua -v
		Error "Unsupported lua version"
	fi
}

Build() {
	make --no-print-directory -C ${Set} &&
	Success "build"	|| Error "build"
	echo
}

Test() {
	${Tester} ${Set} "$@"
	read
}

#### Main ####

Prepare
FindLua
Build
