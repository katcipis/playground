package br.com.oncast;
import java.util.Set;
import br.com.oncast.Book;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public abstract class BookSortOperation {
	
	public enum Direction { ASCENDING, DESCENDING };
	
	private Direction direction;
	
	/**
	 * Constructs a BookSortOperation with the given direction.
	 *
	 * @param direction The direction of the sort operation.
	 */
	public BookSortOperation(Direction direction) {
	    this.direction = direction;	
	}
	
	/**
	 * Get the book's Set reordered according to a implemented sort operation.
	 *
	 * @return a Set of Books ordered according to the implemented sort operation.
	 */
	public Set<Book> sort(Set<Book> books){
		
		if (this.direction == Direction.ASCENDING) {
		    return this.sortAscending(books);
		}
		
		return this.sortDescending(books);
	}

	/**
	 * Get the book's Set reordered according to a implemented sort operation on ascending direction.
	 *
	 * @return a Set of Books ordered according to a implemented sort operation on ascending direction.
	 */
	protected abstract Set<Book> sortAscending(Set<Book> books);
	
	/**
	 * Get the book's Set reordered according to a implemented sort operation on descending direction.
	 *
	 * @return a Set of Books ordered according to a implemented sort operation on descending direction.
	 */
	protected abstract Set<Book> sortDescending(Set<Book> books);
}
