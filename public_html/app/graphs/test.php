<?php    
 /* CAT:Stacked chart */ 
$path = '/home4/orcapilo/orcapilot';
set_include_path(get_include_path() . PATH_SEPARATOR . $path);
 /* pChart library inclusions */ 
 include '/home4/orcapilo/orcapilot/framework_0_2/pChart/class/pData.class.php'; 
 include '/home4/orcapilo/orcapilot/framework_0_2/pChart/class/pDraw.class.php'; 
 include '/home4/orcapilo/orcapilot/framework_0_2/pChart/class/pImage.class.php'; 

 /* Create and populate the pData object */ 
 $MyData = new pData();   
 $MyData->addPoints(array(4000000,VOID,VOID,12000000,8000000,3000000),"Gauffin"); 
 $MyData->addPoints(array(3000000,12000000,15000000,8000000,5000000,5000000),"Lumber"); 
 $MyData->addPoints(array(2000000,7000000,5000000,18000000,19000000,22000000),"Wanting"); 
 $MyData->setAxisName(0,"ISK"); 
 $MyData->addPoints(array("Jan","Feb","Mar","Apr","May","Jun"),"Labels"); 
 $MyData->setSerieDescription("Labels","Months"); 
 $MyData->setAbscissa("Labels"); 

//  /* Normalize all the data series to 100% */ 
//  $MyData->normalize(100,"%"); 

 /* Create the pChart object */ 
 $myPicture = new pImage(700,230,$MyData); 
 $myPicture->drawGradientArea(0,0,700,230,DIRECTION_VERTICAL,array("StartR"=>24,"StartG"=>24,"StartB"=>24,"EndR"=>180,"EndG"=>180,"EndB"=>180,"Alpha"=>100)); 
 $myPicture->drawGradientArea(0,0,700,230,DIRECTION_HORIZONTAL,array("StartR"=>240,"StartG"=>240,"StartB"=>240,"EndR"=>180,"EndG"=>180,"EndB"=>180,"Alpha"=>20)); 
 
 /* Set the default font properties */ 
 $myPicture->setFontProperties(array("FontName"=>"/home4/orcapilo/orcapilot/framework_0_2/pChart/fonts/pf_arma_five.ttf","FontSize"=>6)); 

 /* Draw the scale and the chart */ 
 $myPicture->setGraphArea(60,20,680,190); 
 $myPicture->drawScale(array("DrawSubTicks"=>TRUE,"Mode"=>SCALE_MODE_ADDALL)); 
 $myPicture->setShadow(TRUE,array("X"=>1,"Y"=>1,"R"=>0,"G"=>0,"B"=>0,"Alpha"=>10)); 
 $myPicture->drawStackedBarChart(array("DisplayValues"=>TRUE,"DisplayColor"=>DISPLAY_AUTO,"Gradient"=>TRUE,"Surrounding"=>30,"InnerSurrounding"=>20)); 
 $myPicture->setShadow(FALSE); 

 /* Write the chart legend */ 
 $myPicture->drawLegend(480,210,array("Style"=>LEGEND_NOBORDER,"Mode"=>LEGEND_HORIZONTAL)); 

 /* Render the picture (choose the best way) */ 
 $myPicture->autoOutput("images/example.drawStackedBarChart.shaded.png"); 
?>