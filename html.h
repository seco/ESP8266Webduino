// html.h

#ifndef _HTML_h
#define _HTML_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

const char html_index[] PROGMEM = {
	"<!DOCTYPE html>"
	"<html>"
	"<head>"
	"    <link href=\"/ESP8266.css\" rel=\"stylesheet\"/>"
	"    <title></title>"
	"    <script>        function loadDoc(url, cFunction, param) {"
	"        var xhttp;"
	"        xhttp = new XMLHttpRequest();"
	"        xhttp.onreadystatechange = function () {"
	"            if (this.readyState == 4 && this.status == 200) {"
	"                cFunction(this.responseXML);"
	"            }"
	"        };"
	"        xhttp.open(\"POST\", url, false);"
	"        xhttp.setRequestHeader(\"Content-type\", \"application/x-www-form-urlencoded\");"
	"        xhttp.send(param);"
	"    }"
	"    function setPower(responseXML) {"
	"        var rele = responseXML.getElementsByTagName(\"rele\")[0].childNodes[0].nodeValue;"
	"        var status = responseXML.getElementsByTagName(\"status\")[0].childNodes[0].nodeValue;"
	"        if (status == 0)"
	"            document.getElementById(\"power\").innerHTML = \"OFF\" + status;"
	"        else"
	"            document.getElementById(\"power\").innerHTML = \"ON\" + status;"
	"    }    </script>"
	"</head>"
	"<body>    <!--Header---> <h1 id=\"head\">Webduino</h1>"
	"<ul id=\"navigation\">"
	"    <li><span class=\"active\">Home</span></li>"
	"    <li><a href=\"#\" class=\"button hvr-underline-from-center\">Impostazioni</a></li>"
	"    <li><a href=\"#\" class=\"button hvr-underline-from-center\">Rete</a></li>"
	"</ul>    <!--Content--->"
	"<div id=\"content\" class=\"container_16 clearfix\">"
	"    <div class=\"grid_5\">"
	"        <span class=\"box\"><h2>Stato della scheda</h2>"
	"            <p><strong>Date e ora : </strong> %datetime <br/><strong>IP Address : </strong> %ipaddress"
	"                <br/><strong>MAC Address : </strong> %macaddress <br/><strong>ID scheda: </strong> %shieldid <br/><strong>Power"
	"                    : </strong><span id=\"power\"> ON</span><button type=\"button\" onclick=\"loadDoc('power', setPower,'status=1')\">ON</button><button type=\"button\" onclick=\"loadDoc('power', setPower,'status=0')\">OFF</button>"
	"            </p>"
	"        </div>"
	"        <div class=\"box\"><h2>Files</h2>"
	"            <table>"
	"                <tbody>"
	"                <tr>"
	"                    <td>Newton 2</td>"
	"                    <td>8 / 10</td>"
	"                </tr>"
	"                <tr>"
	"                    <td>Wicked Twister</td>"
	"                    <td>9 / 10</td>"
	"                </tr>"
	"                <tr>"
	"                    <td>Forester</td>"
	"                    <td>9.12 / 10</td>"
	"                </tr>"
	"                <tr>"
	"                    <td>Sabertooth</td>"
	"                    <td>"
	"                        <div>8.9 / 10 <input type=\"submit\" value=\"post\"></div>"
	"                    </td>"
	"                </tr>"
	"                </tbody>"
	"            </table>"
	"        </div>"
	"    </div>"
	"</div>    <!--Footer--->"
	"<div id=\"foot\">"
	"    <div class=\"container_16 clearfix\">"
	"        <div class=\"grid_16\"><a href=\"#\">Contact Me</a></div>"
	"    </div>"
	"</div>"
	"<div id=\"demo\"><h1>The XMLHttpRequest Objectx</h1>"
	"    <button type=\"button\" onclick=\"loadDoc('power', myFunction)\"> Change Content</button>"
	"</div>"
	"</body>"
	"</html>"
	""


};

const char html_heater[] PROGMEM = {

	"<body onload='load()'>"
	"<!--Header--->"
	"<h1 id=\"head\">Webduino</h1>"
	"<ul id=\"navigation\">"
	"    <li><a href=\"#\" class=\"button hvr-underline-from-center\">Home</a></li>"
	"    <li><a href=\"#\" class=\"button hvr-underline-from-center\">Impostazioni</a></li>"
	"    <li><a href=\"#\" class=\"button hvr-underline-from-center\">Rete</a></li>"
	"    <li><span class=\"active\">Riscaldamento</span></li>"
	"</ul>"
	"<!--Content--->"
	"<div id=\"content\" class=\"container_16 clearfix\">"
	"    <div class=\"grid_5\">"
	"        <div class=\"box\">"
	""
	"            <h2>Riscaldamento</h2>"
	"            <form action='/command' method='POST' id='heater'>"
	"                <p>"
	"                    <strong>Abilitato : </strong><label class=\"input-toggle\"><input type=\"checkbox\" id=\"heaterEnabled\""
	"                                                                                    name=\"enabled\"><span></span></label><br>"
	"                    <strong>Pin rele : </strong><label id=\"pinSelectValue\" hidden>audi</label>"
	"                    <select id=\"pinSelect\" name=\"pin\">"
	"                        <option value=\"D1\">D1</option>"
	"                        <option value=\"D2\">D2</option>"
	"                        <option value=\"D3\">D3</option>"
	"                        <option value=\"D4\">D4</option>"
	"                        <option value=\"D5\">D5</option>"
	"                    </select>"
	"                    <br><br>"
	"                    <input type='hidden' name='command' value='heatersettings'>"
	"                    <input type='submit' value=\"save\" onclick='whichPressed=this'>"
	"                </p>"
	"            </form>"
	"        </div>"
	""
	"        <div class=\"box\">"
	""
	"            <h2>Riscaldamento</h2>"
	""
	"            <label id=\"summary\">summary</label><br>"
	"            <label id=\"command\">command</label><br>"
	"            <label id=\"timer\">timer</label>"
	""
	"            <form action='/command' method='POST' id='startManualForm'>"
	"                <p>"
	"                    Minutesy:<input type='number' name='duration' value='30' min=\"1\" max=\"30\"><BR>"
	"                    Target:<input type='number' name='target' value='22.0' step='0.10'><BR>"
	"                    Sensor:<input type='radio' name='sensor' value='0' checked>Local<input type='radio' name='sensor'"
	"                                                                                           value='1'>Remote<BR>"
	"                    <input type='hidden' name='command' value='manual'>"
	"                    <input type='submit' value='start manual' onclick='whichPressed=this'>"
	"                </p>"
	"            </form>"
	""
	"            <form action='/command' method='POST' id='manualOffForm'>"
	"                <p>"
	"                    Minutesx:<input type='number' name='duration' value='30' min=\"1\" max=\"30\"><BR>"
	"                    <input type='hidden' name='command' value='manualoff'>"
	"                    <input type='submit' value='start manual off' onclick='whichPressed=this'>"
	"                </p>"
	"            </form>"
	""
	""
	"            <div id='manual'>"
	"                <form action='/command' method='POST' id='stopManualForm'>"
	"                    <p>"
	"                        <input type='hidden' name='command' value='manualend'>"
	"                        <input type='submit' value='stop manual' onclick='whichPressed=this'>"
	"                    </p>"
	"                </form>"
	"            </div>"
	""
	"        </div>"
	""
	""
	"    </div>"
	"</div>"
	"<!--Footer--->"
	"<div id=\"foot\">"
	"    <div class=\"container_16 clearfix\">"
	"        <div class=\"grid_16\"><a href=\"#\">Contact Me</a></div>"
	"    </div>"
	"</div>"
	"</body>"
	"</html>"
	""


};

#endif
