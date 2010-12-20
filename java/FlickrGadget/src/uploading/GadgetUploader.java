package uploading;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;

import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;

import com.aetrion.flickr.Flickr;
import com.aetrion.flickr.FlickrException;
import com.aetrion.flickr.REST;
import com.aetrion.flickr.RequestContext;
import com.aetrion.flickr.auth.Auth;
import com.aetrion.flickr.auth.AuthInterface;
import com.aetrion.flickr.auth.Permission;
import com.aetrion.flickr.uploader.UploadMetaData;
import com.aetrion.flickr.uploader.Uploader;

public class GadgetUploader {
	
	private final Uploader flickrUploader;
	private final Flickr flickr;
	private final RequestContext requestContext;
	private final AuthInterface authInterface;
	private final String frob;
	private static GadgetUploader me;
	
	private GadgetUploader() throws ParserConfigurationException, IOException, SAXException, FlickrException{
		
		this.flickr = new Flickr(FlickrAPI.FLICKR_KEY.value, new REST());
		Flickr.debugStream = false;
		this.requestContext = RequestContext.getRequestContext();
		this.requestContext.setSharedSecret(FlickrAPI.FLICKR_SECRET.value);
		this.authInterface = flickr.getAuthInterface();
		this.frob = authInterface.getFrob();
		this.flickrUploader = new Uploader(flickr.getApiKey(), flickr.getTransport());
	}
	
	public static GadgetUploader getUploader(){
		if(me == null)
			try {
				me = new GadgetUploader();
			} catch (ParserConfigurationException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			} catch (SAXException e) {
				e.printStackTrace();
			} catch (FlickrException e) {
				e.printStackTrace();
			}
		
		return me;
	}
	
	public static void restartUploader(){
		me = null;
	}
	
	public URL getAuthenticationUrl() throws IOException, SAXException{
		
        return this.authInterface.buildAuthenticationUrl(Permission.WRITE, this.frob);	
	}
	
	public Auth getAuthentication() throws IOException, SAXException, FlickrException{
		
		return this.authInterface.getToken(frob);
	}
	
	public boolean isAuthenticated() throws IOException, SAXException, FlickrException{
		return this.authInterface.getToken(frob).getPermission().equals(Permission.WRITE);
	}
	
	public void setAuthentication(Auth autentication){
		RequestContext.getRequestContext().setAuth(autentication);
	}
	
	/*
	 * Upload a photo on the authenticated account
	 * remember to first authenticate the given URL
	 * and setting the authentication before uploading 
	 * the photo 
	 */
	public void upload(String filename, UploadMetaData photo_details) throws FlickrException, FileNotFoundException{
		
		FileInputStream photo = new FileInputStream(filename);
	
		try {

			flickrUploader.upload(photo, new UploadMetaData());

		} catch (IOException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		}
	}

}
