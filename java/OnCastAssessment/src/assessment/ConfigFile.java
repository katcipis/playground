package assessment;

public enum ConfigFile {
	FULL_LOCATION("./src/assessment/config/config.xml"), 
	NO_UPPER_LOCATION("./src/assessment/config/configWithoutUpper.xml"),
	NO_SUPRESS_BLANK_LOCATION("./src/assessment/config/configWithoutSupressBlank.xml"),
	INVALID_LOCATION("./src/assessment/config/invalidConfig.xml");
	
	private final String location;
	
	private ConfigFile(String location){
		this.location = location;
	}
	
	public String getFileLocation(){
		return this.location;
	}
}
