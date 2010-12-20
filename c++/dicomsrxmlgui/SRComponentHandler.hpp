#ifndef SRCOMPONENTHANDLER_HPP_
#define SRCOMPONENTHANDLER_HPP_
#include <string>
#include <vector>

class SRComponentHandler {
  public:
    SRComponentHandler();
    virtual ~SRComponentHandler();

  protected:
    bool IsComponentWithContentSequence(std::string code_value);
    bool ComponentHasIndependentChildren(std::string code_value);
    bool IsComponentWithChildren(std::string code_value);
    void InitializeComponentsList();
    
  private:
    std::vector<std::string> m_components; 
    std::vector<std::string> m_components_with_children;
    std::vector<std::string> m_components_with_ichildren;
};

#endif /*SRCOMPONENTHANDLER_HPP_*/
