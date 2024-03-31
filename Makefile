.SILENT:

build-docs:
	doxygen && mv docs/html/* docs/ && rm -rf docs/html