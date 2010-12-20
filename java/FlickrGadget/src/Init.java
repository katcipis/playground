import gui.GetAuthenticationGui;

import java.applet.Applet;
import java.io.IOException;

import org.xml.sax.SAXException;

import com.aetrion.flickr.FlickrException;

import uploading.GadgetUploader;

public class Init extends Applet{

	
	private static final long serialVersionUID = -7090217712324828677L;

	public void uploadButtonClicked(){
		try {
			if(GadgetUploader.getUploader().isAuthenticated()){
				// do things
			}else{
				new GetAuthenticationGui();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		} catch (FlickrException e) {
			e.printStackTrace();
		}
				
	}
	
}
