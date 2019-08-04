syntax on
set sw=4
set ts=4
set softtabstop=4
set smartindent
set expandtab
set nu

map <F8>  :call Debug()<CR>
map <F9>  :call Compile()<CR>
map <F10> :call Run()<CR>

func! Compile()
	exec "w"
	exec "!g++ % -o %< -g -Wall -std=c++11"
endfunc

func! Run()
	exec "!time ./%<"
endfunc

func! Gdb()
	exec "!gdb %<"
endfunc