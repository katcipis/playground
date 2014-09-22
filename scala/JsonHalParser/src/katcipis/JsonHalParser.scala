package katcipis
import scala.util.matching.Regex

class JsonHalParser (jsonHal : String) {
  
  var _jsonHal = jsonHal
  
  def getRelationUri (relationName : String) : String = {
      var patternString = relationName + """":\{"href":"([/a-zA-Z]+)"\}.*"""
      var pattern = new Regex(patternString)
      var m = pattern.findFirstMatchIn(_jsonHal).get      
      return m.group(1)
  }

}