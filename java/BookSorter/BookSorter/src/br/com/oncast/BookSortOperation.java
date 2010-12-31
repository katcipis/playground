package br.com.oncast;
import java.util.Comparator;
import java.util.Set;
import java.util.TreeSet;
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
	 * @param books The Set of books to be sorted.
	 * @return a Set of Books sorted according to the implemented sort operation.
	 * @throws OrderingException 
	 */
	public Set<Book> sort(Set<Book> books) throws OrderingException{
		if (books == null) {
			throw new OrderingException();
		}
		
		if (books.isEmpty()) {
			return books;
		}
		
		if (this.direction == Direction.ASCENDING) {
		    return this.sortAscending(books);
		}
		
		return this.sortDescending(books);
	}

	/**
	 * Get the book's Set sorted according to a implemented comparator on ascending direction.
	 *
	 * @param books The Set of books to be sorted.
	 * @return a Set of Books ordered according to a implemented comparator on ascending direction.
	 */
	private  Set<Book> sortAscending(Set<Book> books){
		TreeSet<Book> ordered = new TreeSet<Book>(getAscendingComparator());
		ordered.addAll(books);
		return ordered;
	}
	
	/**
	 * Get the book's Set sorted according to a implemented comparator on descending direction.
	 *
	 * @param books The Set of books to be sorted.
	 * @return a Set of Books ordered according to a implemented comparator on descending direction.
	 */
	private Set<Book> sortDescending(Set<Book> books){
		TreeSet<Book> ordered = new TreeSet<Book>(getDescendingComparator());
		ordered.addAll(books);
		return ordered;
	}
	
	/**
	 * Get a comparator on ascending direction.
	 *
	 * @return a comparator on ascending direction.
	 */
	protected abstract Comparator<Book> getAscendingComparator();
	
	/**
	 * Get a comparator on descending direction.
	 *
	 * @return a comparator on descending direction.
	 */
	protected abstract Comparator<Book> getDescendingComparator();
}
