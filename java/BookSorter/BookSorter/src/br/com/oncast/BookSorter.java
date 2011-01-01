package br.com.oncast;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */
public class BookSorter {

	private List<BookSortOperation> sortOperations;
	
	/**
	 * Constructs a BookSorter that will sort books using the given sort operations.
	 * The first sort operation on the list is the one with most priority, the last one has least priority.
	 *
	 * @param sortOperations The list of sort operations to be used on this sorter.
	 */
	public BookSorter(List<BookSortOperation> sortOperations){
		this.sortOperations = sortOperations;
	}
	
	/**
	 * Get the book's List reordered according to a defined list of sort operations.
	 *
	 * @param books The List of books to be sorted.
	 * @return a List of Books sorted according to a defined list of sort operations.
	 * @throws OrderingException 
	 */
	public List<Book> sort(List<Book> books) throws OrderingException{
		if (books == null) {
			throw new OrderingException();
		}
		
		List<Book> ordered = new ArrayList<Book>();
		
		for (int i = 0; i < books.size(); i++){
			ordered.add(books.get(i));
		}
		this.sort(ordered, 0);
		return ordered;
	}

	private void sort(List<Book> books, Integer operationsCount) {

		if (operationsCount == this.sortOperations.size()) {
			return;
		}
		
		BookSortOperation operation = this.sortOperations.get(operationsCount);
		List<Book> sortedBooks      = operation.sort(books);
		
		books.clear();
		books.addAll(sortedBooks);
	
		for (int i = 0; i < books.size() - 1; i++) {
			if (operation.stillNeedSorting(books.get(i), books.get(i + 1))) {
				
				int j = i + 1;
				
				while (operation.stillNeedSorting(books.get(j), books.get(j + 1))) {
					j++;
					if (j >= (books.size() - 1)) {
						break;
					}
				}
				
				List<Book> sortedSubList = books.subList(i, j + 1);
				this.sort(sortedSubList, operationsCount + 1);
				i = j + 1;
			}
		}
	}
}
