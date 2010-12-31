package br.com.oncast.tests;

import static org.junit.Assert.*;
import br.com.oncast.Book;
import br.com.oncast.BookSortOperation;
import br.com.oncast.OrderingException;

import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

import org.junit.Test;

/**
 * @author Tiago Katcipis <tiagokatcipis@gmail.com>
 *
 */

public abstract class BookSortOperationTest {
	
	protected abstract BookSortOperation getAscendingOperation();
	
	protected abstract BookSortOperation getDescendingOperation();
	
	protected abstract Set<Book> getUnordered();
	
	protected abstract List<Book> getAscending();
	
	protected abstract List<Book> getDescending();
	
	@Test
	public void canSortBooksOnAscendingOrder() {
		Set<Book> result    = getAscendingOperation().sort(getUnordered());
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
		Set<Book> result    = getDescendingOperation().sort(new HashSet<Book>(getUnordered()));
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
	public void ifAnEmptySetIsGivenReturnsAEmptySet() {
		BookSortOperation oper = getDescendingOperation();
		Set<Book> empty = new TreeSet<Book>();
		
		assertEquals(new TreeSet<Book>(), oper.sort(empty));
	}
	
	@Test(expected = OrderingException.class)
	public void ifTheGivenSetIsNullThrowsAOrderingException(){
		BookSortOperation oper = getDescendingOperation();
		oper.sort(null);
	}
}
