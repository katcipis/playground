package examples;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;

import uploading.FlickrAPI;

import com.aetrion.flickr.Flickr;
import com.aetrion.flickr.FlickrException;
import com.aetrion.flickr.REST;
import com.aetrion.flickr.RequestContext;
import com.aetrion.flickr.auth.Auth;
import com.aetrion.flickr.auth.AuthInterface;
import com.aetrion.flickr.auth.Permission;
import com.aetrion.flickr.uploader.UploadMetaData;
import com.aetrion.flickr.uploader.Uploader;

public class UploaderExample {

	private final Uploader flickrUploader;
	private Flickr flickr;
    private String frob;
    private RequestContext requestContext;
    private AuthInterface authInterface;
    private Auth auth;
    private URL url;
    
	public UploaderExample() throws IOException, SAXException, FlickrException,
			ParserConfigurationException {

		this.autenticate();

		flickrUploader = new Uploader(flickr.getApiKey(), flickr.getTransport());
	}

	private void autenticate() throws IOException, SAXException,
			FlickrException, ParserConfigurationException {
	   
	    flickr = new Flickr(FlickrAPI.FLICKR_KEY.value, new REST());
        Flickr.debugStream = false;
        // Set the shared secret which is used for any calls which require signing.
        requestContext = RequestContext.getRequestContext();
        requestContext.setSharedSecret(FlickrAPI.FLICKR_SECRET.value);
        authInterface = flickr.getAuthInterface();
        try {
            frob = authInterface.getFrob();
        } catch (FlickrException e) {
            e.printStackTrace();
        }
        System.out.println("frob: " + frob);
        url = authInterface.buildAuthenticationUrl(Permission.WRITE, frob);
        System.out.println("Press return after you granted access at this URL:");
        System.out.println(url.toExternalForm());
        BufferedReader infile =
          new BufferedReader ( new InputStreamReader (System.in) );
        infile.readLine();
        try {
            auth = authInterface.getToken(frob);
            System.out.println("Authentication success");
            // This token can be used until the user revokes it.
            System.out.println("Token: " + auth.getToken());
            System.out.println("nsid: " + auth.getUser().getId());
            System.out.println("Realname: " + auth.getUser().getRealName());
            System.out.println("Username: " + auth.getUser().getUsername());
            System.out.println("Permission: " + auth.getPermission());
        } catch (FlickrException e) {
            System.out.println("Authentication failed");
            e.printStackTrace();
        }



	}

	public void uploadPhoto(String filename) {

		FileInputStream photo = null;

		try {
			photo = new FileInputStream(filename);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}

		
		RequestContext.getRequestContext().setAuth(auth);
		
		try {

			flickrUploader.upload(photo, new UploadMetaData());

		} catch (IOException e) {
			e.printStackTrace();
		} catch (FlickrException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws IOException, SAXException,
			FlickrException, ParserConfigurationException {
		UploaderExample uploader = new UploaderExample();
		uploader.uploadPhoto("test.jpg");
	}

}
