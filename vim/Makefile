#FIXME: WE HAVE A SEVERE DUPLICATION ON THIS MAKE !!!
PATHOGEN_BUNDLE_DIR=$(HOME)/.vim/bundle

install:
	cp vimrc $(HOME)/.vimrc
	cp -pr .vim $(HOME)
	mkdir -p $(HOME)/.vim/autoload
	echo "Installing Pathogen"
	mkdir -p $(PATHOGEN_BUNDLE_DIR) 
	curl -Sso $(HOME)/.vim/autoload/pathogen.vim https://raw.github.com/tpope/vim-pathogen/master/autoload/pathogen.vim
	echo "Installing Tabular"
	rm -rf $(PATHOGEN_BUNDLE_DIR)/tabular
	mkdir -p $(PATHOGEN_BUNDLE_DIR)/tabular
	git clone git://github.com/godlygeek/tabular.git $(PATHOGEN_BUNDLE_DIR)/tabular

install-js:
	echo "Installing Vim Node"
	rm -rf $(PATHOGEN_BUNDLE_DIR)/node
	mkdir -p $(PATHOGEN_BUNDLE_DIR)/node
	git clone git://github.com/moll/vim-node.git $(PATHOGEN_BUNDLE_DIR)/node
	echo "Installing Javascript Syntax"
	rm -rf $(PATHOGEN_BUNDLE_DIR)/vim-javascript-syntax
	mkdir -p $(PATHOGEN_BUNDLE_DIR)/vim-javascript-syntax
	git clone git://github.com/jelera/vim-javascript-syntax.git $(PATHOGEN_BUNDLE_DIR)/vim-javascript-syntax
	echo "Installing Javascript Indent"
	rm -rf $(PATHOGEN_BUNDLE_DIR)/vim-javascript-indent
	mkdir -p $(PATHOGEN_BUNDLE_DIR)/vim-javascript-indent
	git clone git://github.com/vim-scripts/JavaScript-Indent.git $(PATHOGEN_BUNDLE_DIR)/vim-javascript-indent
