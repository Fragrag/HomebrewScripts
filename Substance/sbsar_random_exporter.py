import os
import random

import sd
from sd.tools import io
from sd.ui.graphgrid import *
from sd.api.sbs.sdsbscompgraph import *
from sd.api.sdvaluecolorrgba import *
from sd.api.sdvalueusage import *
from sd.api.sdvaluearray import *
from sd.api.sdvalueenum import *
from sd.api.sdtypeusage import *
from sd.api.sdresourcebitmap import *
from sd.api.sdresource import *


'''
Workflow SBS(AR) batch exporter random

1) Take in an SBS(AR)
2) Find all adjustable parameters
3) Choose parameters to adjust
4) Set ranges of selected parameters
5) Export SBS(AR) with parameters set randomly (Should have seed for consistent randomness)
'''

CONCRETESBSARPATH = 'D:\Photography\CurrentProjects\StudioClaerbout\aircraft\Aircraft FAL 3d\materials\ground\ground_hero_v2.sbsar'

def main(aSDContext):
    cGridSize = GraphGrid.sGetFirstLevelSize()
    sbsPackageName = os.path.split(__file__)[1].split('.')[0] 

    # =========================================================================
    # Create a new Package
    sdPackageMgr = aSDContext.getSDApplication().getPackageMgr()
    sdPackage = sdPackageMgr.newUserPackage() #TODO: Should be set to currently open package or as an argument

    # =========================================================================
    # Create a new Substance Compositing Graph in this package
    sdSBSCompGraph = SDSBSCompGRaph.sNew(sdPackage)

    #   - Set the graph identifier
    sdSBSCompGraph.setIdentifier.sNew(sbsPackageName) #TODO: Should be automated

    sdSBSCompNodeConcreteRoughCracked = sdSBSCompGraph.newNode('sbs::compositing::uniform') #TODO: Should be the concrete

    sdSBSCompNodeConcreteRoughCracked.setPosition(float2(-2*cGridSize, cGridSize))

    # Create a material node
    # Load the sbsar
    linkedSDResourceConcreteSBSAR = SDResource.


    # Values that need to be changes in Concrete Rough Cracked:
    # Variation Disorder - variationdisorder - float 0.00 -> 1.00
    # Grunge Selection - grunge_selection - int 1 -> 5
    # Disorder - disorder - float 0.00 -> 1.00
    #   - Change the color property of this node
    #       - Create the value color. The SDValueColorRGBA embeds the base type value of type ColorRGBA
    sdValueColorRGBA = SDValueColorRGBA.sNew(ColorRGBA(0.2, 0.5, 0.8, 1.0))
    sdValueVariationDisorder = random.uniform(0, 1)
    sdValueGrungeSelection = random.randrange(1, 5)
    sdValueDisorder = random.uniform(0, 1)
    #       - Set the color value to the 'outputcolor' input property of the node
    sdSBSCompNodeConcreteRoughCracked.setInputPropertyValueFromId('variationdisorder', sdValueVariationDisorder)
    sdSBSCompNodeConcreteRoughCracked.setInputPropertyValueFromId('grunge_selection', sdValueGrungeSelection)
    sdSBSCompNodeConcreteRoughCracked.setInputPropertyValueFromId('disorder', sdValueDisorder)

    # Create an output Nodes
    sdSBSCompNodeOutputBaseColor = sdSBSCompGraph.newNode('sbs::compositing::output')
    sdSBSCompNodeOutputNormal = sdSBSCompGraph.newNode('sbs::compositing::output')
    sdSBSCompNodeOutputRoughness = sdSBSCompGraph.newNode('sbs::compositing::output')
    # Set posiutions
    sdSBSCompNodeOutputBaseColor.setPosition(float2(2*cGridSize, 0))
    sdSBSCompNodeOutputNormal.setPosition(float2(2*cGridSize, 0))
    sdSBSCompNodeOutputRoughness.setPosition(float2(2*cGridSize, 0))

    #   - Add one usage 'baseColor' to the output node
    #       The usages of an output (or input node) are define from/to an array.
    #       - Create an array value of usages (of undefined size)
    sdValueArrayBaseColor = SDValueArray.sNew(SDTypeUsage.sNew(), 0)
    #       - Create an usage value that embed the usage to add to the node
    sdValueUsageBaseColor = SDValueUsage.sNew(SDUsage.sNew('basecolor', 'RGBA', 'sRGB'))
    #       - Add the usage value to the array
    sdValueArrayBaseColor.pushBack(sdValueUsageBaseColor)
    #       - Set the value array to the 'usages' annotation of the output node
    sdSBSCompNodeOutputBaseColor.setAnnotationPropertyValueFromId('usages', sdValueArrayBaseColor)

    #   - Add one usage 'baseColor' to the output node
    #       The usages of an output (or input node) are define from/to an array.
    #       - Create an array value of usages (of undefined size)
    sdValueArrayNormal = SDValueArray.sNew(SDTypeUsage.sNew(), 0)
    #       - Create an usage value that embed the usage to add to the node
    sdValueUsageNormal = SDValueUsage.sNew(SDUsage.sNew('normal', 'RGBA', 'sRGB'))
    #       - Add the usage value to the array
    sdValueArrayNormal.pushBack(sdValueUsageNormal)
    #       - Set the value array to the 'usages' annotation of the output node
    sdSBSCompNodeOutputNormal.setAnnotationPropertyValueFromId('usages', sdValueArrayNormal)

    #   - Add one usage 'baseColor' to the output node
    #       The usages of an output (or input node) are define from/to an array.
    #       - Create an array value of usages (of undefined size)
    sdValueArrayRoughness = SDValueArray.sNew(SDTypeUsage.sNew(), 0)
    #       - Create an usage value that embed the usage to add to the node
    sdValueUsageRoughness = SDValueUsage.sNew(SDUsage.sNew('normal', 'RGBA', 'sRGB'))
    #       - Add the usage value to the array
    sdValueUsageRoughness.pushBack(sdValueUsageNormal)
    #       - Set the value array to the 'usages' annotation of the output node
    sdSBSCompNodeOutputRoughness.setAnnotationPropertyValueFromId('usages', sdValueUsageRoughness)

    # =========================================================================
    # Create connections
    #   - Connect the Bitmap node to the Blend node
    #       - 'unique_filter_output': The identifier of the output property of the Uniform Node.
    #           This property is Connectable (i.e. SDProperty.isConnectable() is True), it means that a Connector is displayed for this property in the graph,
    #           and a connection can be defined from/to this property.
    #       - 'sdSBSCompNodeOutput': This is the other Node to connect
    #       - 'source.connector': This is the input property of the other Node
    sdSBSCompNodeConcreteRoughCracked.newPropertyConnectionFromId('basecolor', sdSBSCompNodeOutputBaseColor, 'inputNodeOutput.connector')
    sdSBSCompNodeConcreteRoughCracked.newPropertyConnectionFromId('normal', sdSBSCompNodeOutputNormal, 'inputNodeOutput.connector')
    sdSBSCompNodeConcreteRoughCracked.newPropertyConnectionFromId('roughness', sdSBSCompNodeOutputRoughness, 'inputNodeOutput.connector')
