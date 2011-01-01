package br.com.oncast.tests;

import static org.junit.Assert.*;
import br.com.oncast.Book;
import br.com.oncast.BookSortOperation;
import br.com.oncast.OrderingException;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.junit.Test;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public abstract class BookSortOperationTest {
	
	protected abstract BookSortOperation getAscendingOperation();
	
	protected abstract BookSortOperation getDescendingOperation();
	
	protected abstract List<Book> getUnordered();
	
	protected abstract List<Book> getAscending();
	
	protected abstract List<Book> getDescending();
	
	@Test
	public void canSortBooksOnAscendingOrder() {
		List<Book> result    = getAscendingOperation().sort(getUnordered());
		Iterator<Book> iter = result.iterator();
		int i               = 0;
		
		while(iter.hasNext()) {
			Book a = iter.next();
			Book b = getAscending().get(i);
			
			assertEquals(a,b);
			
			i++;
		}
	}

	@Test
	public void canSortBooksOnDescendingOrder() {
		List<Book> result    = getDescendingOperation().sort(new ArrayList<Book>(getUnordered()));
		Iterator<Book> iter = result.iterator();
		int i               = 0;
		
		while(iter.hasNext()) {
			Book a = iter.next();
			Book b = getDescending().get(i);
			
			assertEquals(a,b);
			i++;
		}
	}
	
	@Test
	public void ifAnEmptyListIsGivenReturnsAEmptyList() {
		BookSortOperation oper = getDescendingOperation();
		List<Book> empty = new ArrayList<Book>();
		
		assertEquals(new ArrayList<Book>(), oper.sort(empty));
	}
	
	@Test(expected = OrderingException.class)
	public void ifTheGivenListIsNullThrowsAOrderingException(){
		BookSortOperation oper = getDescendingOperation();
		oper.sort(null);
	}
}
