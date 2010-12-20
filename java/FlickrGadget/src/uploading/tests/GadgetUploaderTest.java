package uploading.tests;

import static org.junit.Assert.assertEquals;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

import org.junit.Test;
import org.xml.sax.SAXException;

import uploading.GadgetUploader;

import com.aetrion.flickr.FlickrException;
import com.aetrion.flickr.auth.Auth;
import com.aetrion.flickr.auth.Permission;
import com.aetrion.flickr.uploader.UploadMetaData;

public class GadgetUploaderTest {

	@Test
	public void ifTheUserAutenticateTheAutenticationWillBeWrite()
			throws IOException, SAXException, FlickrException {

		/*
		 * autenticate the URL in the console, if you not do this the test will
		 * fail
		 */

		GadgetUploader.restartUploader();

		URL url = GadgetUploader.getUploader().getAuthenticationUrl();
		System.out
				.println("Press return after you granted access at this URL:");
		System.out.println(url.toExternalForm());
		BufferedReader infile = new BufferedReader(new InputStreamReader(
				System.in));
		infile.readLine();

		Auth authentication = GadgetUploader.getUploader().getAuthentication();
		assertEquals(authentication.getPermission(), Permission.WRITE);
	}

	@Test(expected = FlickrException.class)
	public void ifTheUserDoesNotAutenticateThrowsAFlickrException()
			throws IOException, SAXException, FlickrException {
		GadgetUploader.restartUploader();
		Auth authentication = GadgetUploader.getUploader().getAuthentication();
		assertEquals(authentication.getPermission(), Permission.NONE);
	}

	@Test(expected = FlickrException.class)
	public void ifYouTryToUploadWithoutAutenticationWillThrowAFlickrException()
			throws FileNotFoundException, FlickrException {
		GadgetUploader.restartUploader();
		GadgetUploader.getUploader().upload("test.jpg", new UploadMetaData());
	}

	@Test(expected = FlickrException.class)
	public void ifYouTryToUploadWithoutSettingTheAutenticationWillThrowAFlickrException()
			throws FlickrException, IOException, SAXException {

		/*
		 * autenticate the URL in the console, if you not do this the test will
		 * fail
		 */
		GadgetUploader.restartUploader();
		URL url = GadgetUploader.getUploader().getAuthenticationUrl();
		System.out
				.println("Press return after you granted access at this URL:");
		System.out.println(url.toExternalForm());
		BufferedReader infile = new BufferedReader(new InputStreamReader(
				System.in));
		infile.readLine();

		GadgetUploader.getUploader().upload("test.jpg", new UploadMetaData());
	}

}
