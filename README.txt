Title of Project : cut Command in Linux

Name: Shubham Abasaheb Devkate
Mis : 111508024

Description:

	Usage: cut OPTION... [FILE]...

	Print selected parts of lines from each FILE to standard output.

	With no FILE, or when FILE is -, read standard input.

	-b, --bytes=LIST        select only these bytes

	-c, --characters=LIST   select only these characters

	-n                      (ignored)

	    --complement        complement the set of selected bytes, characters
				or fields

		--help          display this help and exit.


	Each range is one of:

	N     N'th byte, character or field, counted from 1
	N-    from N'th byte, character or field, to end of line
	N-M   from N'th to M'th (included) byte, character or field
	-M    from first to M'th (included) byte, character or field

