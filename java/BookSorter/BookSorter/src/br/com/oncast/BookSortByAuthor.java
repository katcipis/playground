package br.com.oncast;

import java.util.Comparator;
import br.com.oncast.BookSortOperation;

public class BookSortByAuthor extends BookSortOperation {

	private class AuthorAscendingComparator<T> implements Comparator<Book> {

		@Override
		public int compare(Book book1, Book book2) {
			if (book1.equals(book2)) {
				/* 
				 * Must be consistent with equals or nasty things can
				 * happen on the TreeSet algorithm.
				 * */
			    return 0;
			}
			
			if (book1.getAuthor().equals(book2.getAuthor())) {
				/* 
				 * Again guarantee consistency with equals
				 * Avoiding to return zero since the books aren't equal
				 *  */
				return -1;
			}
			
			return book1.getAuthor().compareTo(book2.getAuthor());
		}	
	}
	
	private class AuthorDescendingComparator<T> implements Comparator<Book> {

		@Override
		public int compare(Book book1, Book book2) {
			if (book1.equals(book2)) {
				/* 
				 * Must be consistent with equals or nasty things can
				 * happen on the TreeSet algorithm.
				 * */
			    return 0;
			}
			
			if (book1.getAuthor().equals(book2.getAuthor())) {
				/* 
				 * Again guarantee consistency with equals
				 * Avoiding to return zero since the books aren't equal
				 *  */
				return -1;
			}
			
			return book2.getAuthor().compareTo(book1.getAuthor());
		}	
	}
	
	public BookSortByAuthor(Direction direction) {
		super(direction);
	}

	@Override
	protected Comparator<Book> getAscendingComparator() {
		return new AuthorAscendingComparator<Book>();
	}

	@Override
	protected Comparator<Book> getDescendingComparator() {
		return new AuthorDescendingComparator<Book>();
	}

}
