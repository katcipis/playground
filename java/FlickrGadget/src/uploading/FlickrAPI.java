package uploading;

public enum FlickrAPI {
	FLICKR_KEY("cc248426d74adc7290febb1f367b5a8b"), FLICKR_SECRET("3412196c110da094");
	
	public final String value;
	
	private FlickrAPI(String s){
		value = s;
	}
}
