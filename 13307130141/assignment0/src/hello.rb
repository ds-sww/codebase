require 'tk'

hello = TkRoot.new { title "Hello" }
TkLabel.new(hello) {
	font TkFont.new('Courier')
	text "\n Hello, world. \n"
	width 18
	height 2
	pack
}

Tk.mainloop