package br.com.oncast;
import java.util.Comparator;
import java.util.Set;
import java.util.TreeSet;

import br.com.oncast.BookSortOperation;


/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public class BookSortByTitle extends BookSortOperation {

	private class titleAscendingComparator<T> implements Comparator<Book> {

		@Override
		public int compare(Book book1, Book book2) {
			if (book1.equals(book2)) {
				/* 
				 * Must be consistent with equals or nasty things can
				 * happen on the TreeSet algorithm.
				 * */
			    return 0;
			}
			
			if (book1.getTitle().equals(book2.getTitle())) {
				/* 
				 * Again guarantee consistency with equals
				 * Avoiding to return zero since the books aren't equal
				 *  */
				return -1;
			}
			
			System.out.println("OK");
			return book1.getTitle().compareTo(book2.getTitle());
		}

		
	}
	
	private class titleDescendingComparator<T> implements Comparator<Book> {

		@Override
		public int compare(Book book1, Book book2) {
			
			if (book1.equals(book2)) {
				/* 
				 * Must be consistent with equals or nasty things can
				 * happen on the TreeSet algorithm.
				 * */
			    return 0;
			}
			
			if (book1.getTitle().equals(book2.getTitle())) {
				/* 
				 * Again guarantee consistency with equals
				 * Avoiding to return zero since the books aren't equal
				 *  */
				return -1;
			}
			
			return book2.getTitle().compareTo(book1.getTitle());
		}
	}
	
	
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
		TreeSet<Book> ordered = new TreeSet<Book>(new titleAscendingComparator<Book>());
		ordered.addAll(books);
		return ordered;
	}
	
	/**
	 * Get the book's Set reordered according to the title on descending direction.
	 *
	 * @return a Set of Books ordered according to the title on descending direction.
	 */
	@Override
	protected Set<Book> sortDescending(Set<Book> books) {
		TreeSet<Book> ordered = new TreeSet<Book>(new titleDescendingComparator<Book>());
		ordered.addAll(books);
		return ordered;
	}

}
