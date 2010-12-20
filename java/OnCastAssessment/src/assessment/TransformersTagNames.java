package assessment;

public enum TransformersTagNames {
	UPPER_CASE("toUpperCase"), BLANK_SPACES("supressBlankChar"), ORDER("order"), ON("On");
	
	private final String tagName;
	
	private TransformersTagNames(String tagName){
		this.tagName = tagName;
	}
	
	public String getTagName(){
		return this.tagName;
	}
	
}
