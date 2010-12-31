package br.com.oncast;

import java.util.List;
import java.util.Set;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */
public class BookSorter {

	private List<BookSortOperation> sortOperations;
	
	/**
	 * Constructs a BookSorter that will sort books using the given sort operations.
	 * The sort operations on the list will be applied on ascending order.
	 *
	 * @param direction The direction of the sort operation.
	 */
	public BookSorter(List<BookSortOperation> sortOperations){
		this.sortOperations = sortOperations;
	}
	
	public Set<Book> sort(Set<Book> books){
		return books;
		
	}
}
