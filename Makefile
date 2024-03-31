.SILENT:

build-docs:
	if [ ! -d docs ]; then git clone git@github.com:AppleBoiy/competitive-contest-355-docs docs ; fi
	doxygen Doxyfile && mv docs/html/* docs/ && rm -rf docs/html