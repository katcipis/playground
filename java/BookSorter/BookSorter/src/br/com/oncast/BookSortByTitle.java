package br.com.oncast;
import java.util.Set;

import br.com.oncast.BookSortOperation;


/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public class BookSortByTitle extends BookSortOperation {

	/**
	 * Constructs a BookSortByTitle with the given direction.
	 *
	 * @param direction The direction of the sort operation.
	 */
	public BookSortByTitle(Direction direction) {
		super(direction);
	}

	/**
	 * Get the book's Set reordered according to the title on ascending direction.
	 *
	 * @return a Set of Books ordered according to the title on ascending direction.
	 */
	@Override
	protected Set<Book> sortAscending(Set<Book> books) {
		return null;
	}
	
	/**
	 * Get the book's Set reordered according to the title on descending direction.
	 *
	 * @return a Set of Books ordered according to the title on descending direction.
	 */
	@Override
	protected Set<Book> sortDescending(Set<Book> books) {
		return null;
	}

}
