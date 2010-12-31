package br.com.oncast.tests;

import static org.junit.Assert.*;
import br.com.oncast.Book;
import br.com.oncast.BookSortOperation;
import br.com.oncast.OrderingException;
import java.util.Set;
import java.util.TreeSet;

import org.junit.Test;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public abstract class BookSortOperationTest {

	public abstract void canSortBooksOnAscendingOrder();
	
	public abstract void canSortBooksOnDescendingOrder();
	
	public abstract BookSortOperation getOperation();
	
	@Test
	public void ifAnEmptySetIsGivenReturnsAEmptySet() {
		BookSortOperation oper = getOperation();
		Set<Book> empty = new TreeSet<Book>();
		
		assertEquals(new TreeSet<Book>(), oper.sort(empty));
	}
	
	@Test(expected = OrderingException.class)
	public void ifTheGivenSetIsNullThrowsAOrderingException(){
		BookSortOperation oper = getOperation();
		oper.sort(null);
	}
}
