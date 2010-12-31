package br.com.oncast;
import java.util.Comparator;


public class BookSortByEditionYear extends BookSortOperation {

	private class EditionYearAscendingComparator<T> implements Comparator<Book> {

		@Override
		public int compare(Book book1, Book book2) {
			if (book1.equals(book2)) {
				/* 
				 * Must be consistent with equals or nasty things can
				 * happen on the TreeSet algorithm.
				 * */
			    return 0;
			}
			
			if (book1.getEditionYear().equals(book2.getEditionYear())) {
				/* 
				 * Again guarantee consistency with equals
				 * Avoiding to return zero since the books aren't equal
				 *  */
				return -1;
			}
			
			return book1.getEditionYear().compareTo(book2.getEditionYear());
		}	
	}
	
	private class EditionYearDescendingComparator<T> implements Comparator<Book> {

		@Override
		public int compare(Book book1, Book book2) {
			if (book1.equals(book2)) {
				/* 
				 * Must be consistent with equals or nasty things can
				 * happen on the TreeSet algorithm.
				 * */
			    return 0;
			}
			
			if (book1.getEditionYear().equals(book2.getEditionYear())) {
				/* 
				 * Again guarantee consistency with equals
				 * Avoiding to return zero since the books aren't equal
				 *  */
				return -1;
			}
			
			return book2.getEditionYear().compareTo(book1.getEditionYear());
		}	
	}
	
	public BookSortByEditionYear(Direction direction) {
		super(direction);
	}

	@Override
	protected Comparator<Book> getAscendingComparator() {
		return new EditionYearAscendingComparator<Book>();
	}

	@Override
	protected Comparator<Book> getDescendingComparator() {
		return new EditionYearDescendingComparator<Book>();
	}

}
