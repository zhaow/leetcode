##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=leetcode
ConfigurationName      :=Debug
WorkspacePath          := "/home/zw/my_cplus/codeliet_workspace"
ProjectPath            := "/home/zw/my_cplus/codeliet_workspace/leetcode"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=zw
Date                   :=03/23/15
CodeLitePath           :="/home/zw/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="leetcode.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(ObjectSuffix): Convert_Sorted_Array_to_Binary_Search_Tree.cpp $(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/zw/my_cplus/codeliet_workspace/leetcode/Convert_Sorted_Array_to_Binary_Search_Tree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(DependSuffix): Convert_Sorted_Array_to_Binary_Search_Tree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(DependSuffix) -MM "Convert_Sorted_Array_to_Binary_Search_Tree.cpp"

$(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(PreprocessSuffix): Convert_Sorted_Array_to_Binary_Search_Tree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Convert_Sorted_Array_to_Binary_Search_Tree.cpp$(PreprocessSuffix) "Convert_Sorted_Array_to_Binary_Search_Tree.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


