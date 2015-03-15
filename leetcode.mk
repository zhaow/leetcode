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
Date                   :=03/14/15
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
Objects0=$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(ObjectSuffix): Remove_Duplicates_from_Sorted_List_II.cpp $(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/zw/my_cplus/codeliet_workspace/leetcode/Remove_Duplicates_from_Sorted_List_II.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(DependSuffix): Remove_Duplicates_from_Sorted_List_II.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(DependSuffix) -MM "Remove_Duplicates_from_Sorted_List_II.cpp"

$(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(PreprocessSuffix): Remove_Duplicates_from_Sorted_List_II.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Remove_Duplicates_from_Sorted_List_II.cpp$(PreprocessSuffix) "Remove_Duplicates_from_Sorted_List_II.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


