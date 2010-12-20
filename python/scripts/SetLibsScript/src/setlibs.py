#! /usr/bin/env python

import xml.dom.minidom
import os
import subprocess
import sys

# Functions definitios goes here #

def RunLdconfigProcess():
    try:
        ld_config_process = subprocess.Popen('sudo ldconfig', shell=True)
        return_code = ld_config_process.wait()
        if (return_code is not 0):
            print 'Something whent wrong while executing ldconfig process'
        else:
            print 'This script has been run with success'
    except OSError, CalledProcessError:
        print 'Something whent wrong while executing ldconfig process'

def AddLibraryPathToSystem():
    try:
        ld_conf_read = open(ld_so_conf_default_path, 'r')
        ld_conf_str = ld_conf_read.read()
        ld_conf_read.close()
        if (ld_conf_str.find(DESTINY_PATH) is -1):
            ld_conf_append = open(ld_so_conf_default_path, 'a')
            ld_conf_append.write(newline)
            ld_conf_append.write(DESTINY_PATH)
            ld_conf_append.close()
            print 'Library path added succesfully'
            print ''
        
    except IOError:
        print ld_so_conf_default_path + ' not found'
        print 'or you dont have superuser privilegies'
        print ''
  
  
def GetFiles(SEARCH_PATH, file):
  directories = os.listdir(SEARCH_PATH)
  
  projects = []
  aux = []
  
  for directorie in directories:
    full_path = os.path.join(SEARCH_PATH, directorie)
    
    if(os.path.isdir(full_path)):
      aux = GetFiles(full_path, file)
      
      for found_file in aux:
        projects.append(found_file)
      
  for directorie in directories: 
    if(directorie == file): 
      full_path = os.path.join(SEARCH_PATH,  directorie)
      projects.append(full_path)
    
  return projects
  
def GetLibPath(project):
  
  xml_file = xml.dom.minidom.parse(project)
  elements = xml_file.getElementsByTagName(configuration_node)
  attributes = [config_artifact_id, config_artifact_name, debug_dir_id]
  project_path = os.path.dirname(project)
  
  for element in elements:
    if(config_artifact_id in element.attributes.keys() and
       config_artifact_name in element.attributes.keys() and
       debug_dir_id in element.attributes.keys()):
      
      debug_dir = element.attributes[debug_dir_id].value
      artifact_extension = element.attributes[config_artifact_id].value
      artifact_name = element.attributes[config_artifact_name].value
      
      if(artifact_extension == desired_artifact):
        lib_path = os.path.join(project_path, debug_dir , (library_suffix + artifact_name + '.' + artifact_extension) )
        return lib_path
      
  return None
  

# <<<<<<<<<<<<<<<<<<<<<<<<<<< Ends Functions Definitions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>#


# Script starts here # 

print 'This script must be runned with super user privilegies'
print ''
ARGUMENTS_PASSED = sys.argv

if(len(ARGUMENTS_PASSED) is 3):
  
  SEARCH_PATH = os.path.realpath(ARGUMENTS_PASSED[1])
  DESTINY_PATH = os.path.realpath(ARGUMENTS_PASSED[2])
  
  debug_dir_id = 'name'
  configuration_node = 'configuration'
  config_artifact_id = 'artifactExtension'
  config_artifact_name = 'artifactName'
  desired_artifact = 'so'
  library_suffix = 'lib'
  ld_so_conf_default_path = '/etc/ld.so.conf'
  newline = '\n'
  
  if(os.path.isdir(SEARCH_PATH)):
  
    found_projects = GetFiles(SEARCH_PATH, '.cproject')
    paths_to_valid_libs = []
    
    for project in found_projects:
      path = GetLibPath(project)
      if(path is not None):
        paths_to_valid_libs.append(path)
      
    print 'The folowing projects with shared libraries have been found:'
    print ''
      
    for valid_path in paths_to_valid_libs:
      print valid_path
      
    print ''
    
    if(not os.path.isdir(DESTINY_PATH)):
      print 'Path not found, creating one'
      os.makedirs(DESTINY_PATH)
      print ''
      
    created_links = []
      
    for valid_path in paths_to_valid_libs:
      
      lib_name = os.path.basename(valid_path)
      full_path = os.path.join(DESTINY_PATH , lib_name)
      created_links.append(full_path)
      
      if(not os.path.islink(full_path)):
        os.symlink(valid_path, full_path)  
      
    print 'The following symbolics links have been made:'
    print ''
    
    for link in created_links:
      print link
      
    print ''
    print 'Now adding the library path to /etc/ld.so.conf'
    print ''
    
    AddLibraryPathToSystem()
       
    print 'Now running ldconfig process:'
    print ''
    
    RunLdconfigProcess()
    
    
  else:
    
    print 'Path not found'
    
else:
  
  print 'Argument is missing, insert the projects location and the destination location'