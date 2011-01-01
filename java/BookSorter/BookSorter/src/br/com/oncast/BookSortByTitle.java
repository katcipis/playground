package br.com.oncast;
import java.util.Comparator;
import br.com.oncast.BookSortOperation;


/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public class BookSortByTitle extends BookSortOperation {

	private class TitleAscendingComparator<T> implements Comparator<Book> {

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
			
			return book1.getTitle().compareTo(book2.getTitle());
		}	
	}
	
	private class TitleDescendingComparator<T> implements Comparator<Book> {

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


	@Override
	protected Comparator<Book> getAscendingComparator() {
		return new TitleAscendingComparator<Book>();
	}


	@Override
	protected Comparator<Book> getDescendingComparator() {
		return new TitleDescendingComparator<Book>();
	}


	@Override
	public boolean stillNeedSorting(Book book, Book otherBook) {
		return book.getTitle().equals(otherBook.getTitle());
	}

}
