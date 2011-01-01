package br.com.oncast;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
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
	 * Get the book's List reordered according to a implemented sort operation.
	 *
	 * @param books The List of books to be sorted.
	 * @return a List of Books sorted according to the implemented sort operation.
	 * @throws OrderingException 
	 */
	public List<Book> sort(List<Book> books) throws OrderingException{
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
	 * Checks if two books have the same sorting attribute, indicating that they still need to be sorted by another BookSortOperation.
	 *
	 * @param book A book instance.
	 * @param otherBook Another book instance.
	 * @return a List of Books ordered according to a implemented comparator on ascending direction.
	 */
	public abstract boolean stillNeedSorting(Book book, Book otherBook);
	
	/**
	 * Get the book's List sorted according to a implemented comparator on ascending direction.
	 *
	 * @param books The List of books to be sorted.
	 * @return a List of Books ordered according to a implemented comparator on ascending direction.
	 */
	private  List<Book> sortAscending(List<Book> books){
		TreeSet<Book> ordered = new TreeSet<Book>(getAscendingComparator());
		ordered.addAll(books);
		List<Book> result = new ArrayList<Book>();
		Iterator<Book> orderedIterator = ordered.iterator();
		
		while (orderedIterator.hasNext()) {
			result.add(orderedIterator.next());
		}
		
		return result;
	}
	
	/**
	 * Get the book's List sorted according to a implemented comparator on descending direction.
	 *
	 * @param books The List of books to be sorted.
	 * @return a List of Books ordered according to a implemented comparator on descending direction.
	 */
	private List<Book> sortDescending(List<Book> books){
		TreeSet<Book> ordered = new TreeSet<Book>(getDescendingComparator());
		ordered.addAll(books);
		List<Book> result = new ArrayList<Book>();
		Iterator<Book> orderedIterator = ordered.iterator();
		
		while (orderedIterator.hasNext()) {
			result.add(orderedIterator.next());
		}
		
		return result;
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
