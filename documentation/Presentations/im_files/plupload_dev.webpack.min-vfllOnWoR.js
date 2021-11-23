define(["mOxie"],(function(e){return(function(e){var t={};function r(i){if(t[i])return t[i].exports;var n=t[i]={i:i,l:!1,exports:{}};return e[i].call(n.exports,n,n.exports,r),n.l=!0,n.exports}return r.m=e,r.c=t,r.d=function(e,t,i){r.o(e,t)||Object.defineProperty(e,t,{enumerable:!0,get:i})},r.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},r.t=function(e,t){if(1&t&&(e=r(e)),8&t)return e;if(4&t&&"object"==typeof e&&e&&e.__esModule)return e;var i=Object.create(null);if(r.r(i),Object.defineProperty(i,"default",{enumerable:!0,value:e}),2&t&&"string"!=typeof e)for(var n in e)r.d(i,n,function(t){return e[t]}.bind(null,n));return i},r.n=function(e){var t=e&&e.__esModule?function(){return e.default}:function(){return e};return r.d(t,"a",t),t},r.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},r.p="",r(r.s=0)})({"./plupload_dev-2.0.0.js":
/*!*******************************!*\
  !*** ./plupload_dev-2.0.0.js ***!
  \*******************************/
/*! no static exports found */function(e,t,r){var i=r(/*! mOxie */"mOxie");(function(e,t,r){var i=e.setTimeout,n={};var s,o,a,l={VERSION:"2.0.0beta",STOPPED:1,STARTED:2,QUEUED:1,UPLOADING:2,COMMITTING:3,FAILED:4,DONE:5,GENERIC_ERROR:-100,HTTP_ERROR:-200,IO_ERROR:-300,SECURITY_ERROR:-400,INIT_ERROR:-500,FILE_SIZE_ERROR:-600,FILE_EXTENSION_ERROR:-601,FILE_DUPLICATE_ERROR:-602,IMAGE_FORMAT_ERROR:-700,IMAGE_MEMORY_ERROR:-701,IMAGE_DIMENSIONS_ERROR:-702,OVER_QUOTA_ERROR:-708,BLOCKS_MISSING_ERROR:-703,COMMIT_HTTP_ERROR:-704,UPLOAD_BLOCK_ERROR:-705,CHUNKS_NOT_ENABLED_ERROR:-706,SERVER_HASH_RESPONSE_ERROR:-707,BLOCK_RUNTIME_ID_MISSING:-709,CLIENT_HASH_EMPTY_ERROR:-710,SERVER_HASH_EMPTY_ERROR:-711,HASHES_NOT_EQUAL_ERROR:-712,BLOCK_INDEX_ERROR:-713,BLOCK_EMPTY_ERROR:-714,BLOB_EMPTY_ERROR:-715,CLIENT_HASH_DIGEST_ERROR:-716,FILE_READER_NULL_RESULT_ERROR:-717,COMMIT_READINESS_ERROR:-718,SERVER_RESPONSE_ERROR:-719,SERVER_TOKEN_EMPTY_ERROR:-720,BLOB_MISSING_ERROR:-721,SERVER_TOKENS_MISSING_ERROR:-722,mimeTypes:t.mimes,ua:t.ua,typeOf:t.typeOf,extend:t.extend,guid:t.guid,each:t.each,getPos:t.getPos,getSize:t.getSize,xmlEncode:function(e){var t={"<":"lt",">":"gt","&":"amp",'"':"quot","'":"#39"};return e?(""+e).replace(/[<>&\"\']/g,(function(e){return t[e]?"&"+t[e]+";":e})):e},toArray:t.toArray,inArray:t.inArray,addI18n:t.addI18n,translate:t.translate,isEmptyObj:t.isEmptyObj,hasClass:t.hasClass,addClass:t.addClass,removeClass:t.removeClass,getStyle:t.getStyle,addEvent:t.addEvent,removeEvent:t.removeEvent,removeAllEvents:t.removeAllEvents,cleanName:function(e){var t,r;for(r=[/[\300-\306]/g,"A",/[\340-\346]/g,"a",/\307/g,"C",/\347/g,"c",/[\310-\313]/g,"E",/[\350-\353]/g,"e",/[\314-\317]/g,"I",/[\354-\357]/g,"i",/\321/g,"N",/\361/g,"n",/[\322-\330]/g,"O",/[\362-\370]/g,"o",/[\331-\334]/g,"U",/[\371-\374]/g,"u"],t=0;t<r.length;t+=2)e=e.replace(r[t],r[t+1]);return e=(e=e.replace(/\s+/g,"_")).replace(/[^a-z0-9_\-\.]+/gi,"")},buildUrl:function(e,t){var r="";return l.each(t,(function(e,t){r+=(r?"&":"")+encodeURIComponent(t)+"="+encodeURIComponent(e)})),r&&(e+=(e.indexOf("?")>0?"&":"?")+r),e},formatSize:function(e){return void 0===e||/\D/.test(e)?l.translate("N/A"):e>1099511627776?Math.round(e/1099511627776,1)+" "+l.translate("tb"):e>1073741824?Math.round(e/1073741824,1)+" "+l.translate("gb"):e>1048576?Math.round(e/1048576,1)+" "+l.translate("mb"):e>1024?Math.round(e/1024,1)+" "+l.translate("kb"):e+" "+l.translate("b")},parseSize:t.parseSizeStr,predictRuntime:function(e,t){var r,i;return t&&(e.runtimes=t),i=(r=new l.Uploader(e)).runtime,r.destroy(),i},addFileFilter:function(e,t){n[e]=t}};l.addFileFilter("mime_types",(function(e,t,r){o&&e==s||(o=(function(e){var t=[];return l.each(e,(function(e){l.each(e.extensions.split(/,/),(function(e){/^\s*\*\s*$/.test(e)?t.push("\\.*"):t.push("\\."+e.replace(new RegExp("["+"/^$.*+?|()[]{}\\".replace(/./g,"\\$&")+"]","g"),"\\$&"))}))})),new RegExp("("+t.join("|")+")$","i")})(e),s=[].slice.call(e)),o.test(t.name)?r(!0):(this.trigger("Error",{code:l.FILE_EXTENSION_ERROR,message:l.translate("File extension error."),file:t}),r(!1))})),l.addFileFilter("max_file_size",(function(e,t,r){void 0!==t.size&&e&&t.size>e?(this.trigger("Error",{code:l.FILE_SIZE_ERROR,message:l.translate("File size error."),file:t}),r(!1)):r(!0)})),l.addFileFilter("prevent_duplicates",(function(e,t,r){if(e)for(var i=this.files.length;i--;)if(t.name===this.files[i].name&&t.size===this.files[i].size)return this.trigger("Error",{code:l.FILE_DUPLICATE_ERROR,message:l.translate("Duplicate file error."),file:t}),void r(!1);r(!0)})),l.Uploader=function(r){var s,o,a,u,d,c,f=[],_={},g=!1,p={},m={},R=!1;function E(){var e,t,i=0;if(r.waterfall_parallel_uploads)for(t=0;t<f.length;t++)if(f[t].status==l.UPLOADING)return;if(this.state==l.STARTED){for(t=0;t<f.length;t++)e||f[t].status!=l.QUEUED?i++:(e=f[t],this.trigger("BeforeUpload",e)&&(e.status=l.UPLOADING,this.trigger("UploadFile",e)));i==f.length&&(this.state!==l.STOPPED&&(this.state=l.STOPPED,this.trigger("StateChanged")),this.trigger("UploadComplete",f))}}function h(e){e.percent=e.size>0?Math.ceil(e.loaded/e.size*100):100,b()}function b(){var e,t;for(a.reset(),e=0;e<f.length;e++)void 0!==(t=f[e]).size?(a.size+=t.origSize,a.loaded+=t.loaded*t.origSize/t.size):a.size=void 0,t.status==l.DONE?a.uploaded++:t.status==l.FAILED?a.failed++:a.queued++;void 0===a.size?a.percent=f.length>0?Math.ceil(a.uploaded/f.length*100):0:(a.bytesPerSec=Math.ceil(a.loaded/((+new Date-o||1)/1e3)),a.percent=a.size>0?Math.ceil(a.loaded/a.size*100):0)}function O(){var e=this,i=0,n={accept:r.filters.mime_types,runtime_order:r.runtimes,required_caps:m,swf_url:r.flash_swf_url,xap_url:r.silverlight_xap_url};l.each(r.runtimes.split(/\s*,\s*/),(function(e){r[e]&&(n[e]=r[e])})),t.inSeries([function(s){r.browse_button?((u=new t.FileInput(l.extend({},n,{name:r.file_data_name,multiple:r.multi_selection,container:r.container,browse_button:r.browse_button}))).onready=function(){var r=t.Runtime.getInfo(this.ruid);t.extend(e.features,{chunks:r.can("slice_blob"),multipart:r.can("send_multipart"),multi_selection:r.can("select_multiple")}),i++,s()},u.onchange=function(){e.trigger("BeforeFilesAdded",this.files)&&e.addFile(this.files)},u.bind("mouseenter mouseleave mousedown mouseup",(function(e){if(!R){var i=t.get(r.browse_button);i&&(r.browse_button_hover&&("mouseenter"===e.type?t.addClass(i,r.browse_button_hover):"mouseleave"===e.type&&t.removeClass(i,r.browse_button_hover)),r.browse_button_active&&("mousedown"===e.type?t.addClass(i,r.browse_button_active):"mouseup"===e.type&&t.removeClass(i,r.browse_button_active)),i=null)}})),u.bind("mousedown",(function(){e.trigger("Browse")})),u.bind("error runtimeerror",(function(){u=null,s()})),u.init()):s()},function(s){r.drop_element?((d=new t.FileDrop(l.extend({},n,{drop_zone:r.drop_element}))).onready=function(){var r=t.Runtime.getInfo(this.ruid);e.features.dragdrop=r.can("drag_and_drop"),i++,s()},d.ondrop=function(){e.trigger("DragAndDrop"),e.addFile(this.files)},d.bind("error runtimeerror",(function(){d=null,s()})),d.init()):s()}],(function(){"function"==typeof r.init?r.init(e):l.each(r.init,(function(t,r){e.bind(r,t)})),i?e.trigger("PostInit"):e.trigger("Error",{code:l.INIT_ERROR,message:l.translate("Init error.")})}))}function v(e,r,i){var n=new t.Image;try{n.onload=function(){n.downsize(r.width,r.height,r.crop,r.preserve_headers)},n.onresize=function(){i(this.getAsBlob(e.type,r.quality)),this.destroy()},n.onerror=function(){i(e)},n.load(e)}catch(t){i(e)}}a=new l.QueueProgress,(r=l.extend({runtimes:t.Runtime.order,max_retries:0,multipart:!0,multi_selection:!0,file_data_name:"file",flash_swf_url:"js/Moxie.swf",silverlight_xap_url:"js/Moxie.xap",send_chunk_number:!0},r)).resize&&(r.resize=l.extend({preserve_headers:!0,crop:!1},r.resize)),"array"===l.typeOf(r.filters)&&(r.filters={mime_types:r.filters}),r.filters=l.extend({mime_types:[],prevent_duplicates:!!r.prevent_duplicates,max_file_size:r.max_file_size},r.filters),r.filters.max_file_size=l.parseSize(r.filters.max_file_size)||0,r.chunk_size=l.parseSize(r.chunk_size)||0,r.required_features=m=(function(e){var t=e.required_features,r={};function i(e,t,i){var n={chunks:"slice_blob",resize:"send_binary_string",jpgresize:"send_binary_string",pngresize:"send_binary_string",progress:"report_upload_progress",multi_selection:"select_multiple",max_file_size:"access_binary",dragdrop:"drag_and_drop",drop_element:"drag_and_drop",headers:"send_custom_headers",canSendBinary:"send_binary",triggerDialog:"summon_file_dialog"};n[e]?r[n[e]]=t:i||(r[e]=t)}return"string"==typeof t?l.each(t.split(/\s*,\s*/),(function(e){i(e,!0)})):"object"==typeof t?l.each(t,(function(e,t){i(t,e)})):!0===t&&(e.multipart||(r.send_binary_string=!0),e.chunk_size>0&&(r.slice_blob=!0),l.each(e,(function(e,t){i(t,!!e,!0)}))),r})(l.extend({},r)),l.extend(this,{id:l.guid(),state:l.STOPPED,features:{},runtime:t.Runtime.thatCan(m,r.runtimes),files:f,settings:r,total:a,init:function(){var n=this;if(r.browse_button=t.get(r.browse_button),r.drop_element=t.get(r.drop_element),"function"==typeof r.preinit?r.preinit(n):l.each(r.preinit,(function(e,t){n.bind(t,e)})),!r.browse_button||!r.url)return void this.trigger("Error",{code:l.INIT_ERROR,message:l.translate("Init error.")});function a(e){Object.keys(e).forEach((function(t){e[t].abort()}))}function u(){a(_),_={}}n.bind("FilesAdded",(function(e,t){[].push.apply(f,t),i((function(){n.trigger("QueueChanged"),n.refresh()}),1)})),n.bind("CancelUpload",(function(){r.waterfall_parallel_uploads?(s&&s.abort(),g=!0,u()):c&&c.abort()})),r.unique_names&&n.bind("BeforeUpload",(function(e,t){var r=t.name.match(/\.([^.]+)$/),i="part";r&&(i=r[1]),t.target_name=t.id+"."+i})),n.bind("UploadFile",(function(n,o){var d,f=n.settings.url,p=n.features,R=r.chunk_size,E=r.max_retries,h=0;function b(){507!==c.status&&E-- >0?i(O,1):(o.loaded=h,n.trigger("Error",{code:l.HTTP_ERROR,message:l.translate("HTTP Error."),file:o,response:c.responseText,status:c.status,responseHeaders:c.getAllResponseHeaders()}))}function O(){var e,s,a,u;o.status!=l.DONE&&o.status!=l.FAILED&&n.state!=l.STOPPED&&(a={name:o.target_name||o.name},R&&p.chunks&&d.size>R?(u=Math.min(R,d.size-h),e=d.slice(h,h+u)):(u=d.size,e=d),R&&p.chunks?r.send_chunk_number?(a.chunk=Math.ceil(h/R),a.chunks=Math.ceil(d.size/R)):(a.offset=h,a.total=d.size):(a.chunk=0,a.chunks=1),(c=new t.XMLHttpRequest).withCredentials=!0,c.upload&&(c.upload.onprogress=function(e){o.loaded=Math.min(o.size,h+e.loaded),n.trigger("UploadProgress",o,!0)}),c.onload=function(){c.status>=400?b():(u<d.size?(e.destroy(),h+=u,o.loaded=Math.min(h,d.size),n.trigger("ChunkUploaded",o,{offset:o.loaded,total:d.size,response:c.responseText,status:c.status,responseHeaders:c.getAllResponseHeaders()}),"Android Browser"===t.Env.browser&&n.trigger("UploadProgress",o,!0)):o.loaded=o.size,e=s=null,!h||h>=d.size?(o.size!=o.origSize&&(d.destroy(),d=null),n.trigger("UploadProgress",o,!0),o.status=l.DONE,n.trigger("FileUploaded",o,{response:c.responseText,status:c.status,responseHeaders:c.getAllResponseHeaders()})):(E=r.max_retries,i(O,1)))},c.onerror=function(){b()},c.onloadend=function(){this.destroy(),c=null},n.settings.multipart&&p.multipart?(a.name=o.target_name||o.name,c.open("post",f,!0),l.each(n.settings.headers,(function(e,t){c.setRequestHeader(t,e)})),s=new t.FormData,l.each(l.extend(a,n.settings.multipart_params),(function(e,t){s.append(t,e)})),s.append(n.settings.file_data_name,e),c.send(s,{runtime_order:n.settings.runtimes,required_caps:m,swf_url:n.settings.flash_swf_url,xap_url:n.settings.silverlight_xap_url})):(f=l.buildUrl(n.settings.url,l.extend(a,n.settings.multipart_params)),c.open("post",f,!0),c.setRequestHeader("Content-Type","application/octet-stream"),l.each(n.settings.headers,(function(e,t){c.setRequestHeader(t,e)})),c.send(e,{runtime_order:n.settings.runtimes,required_caps:m,swf_url:n.settings.flash_swf_url,xap_url:n.settings.silverlight_xap_url})))}function S(){if(d){var r=d.size;if(d.size){if(o.status!=l.DONE&&o.status!=l.FAILED&&n.state!=l.STOPPED)if(p.chunks){for(var c,m,E=!!(e.crypto&&e.crypto.subtle&&e.crypto.subtle.digest),h=Math.ceil(r/R),b=0,O=[],v=0,S=[],y=[],I=h-1,T=0;T<h;T++)y.push(void 0),S.push(void 0),O.push(0);E?(m=function(){A()},(function e(t){var r=z(t);if(!r.ruid)return u(),void n.trigger("Error",{code:l.BLOCK_RUNTIME_ID_MISSING_ERROR,message:l.translate("Block ruid missing."),file:o});r.connectRuntime(r.ruid);var i=new FileReader;s=i,i.onloadend=function(s){if(!s.target.result&&!g)return u(),void n.trigger("Error",{code:l.FILE_READER_NULL_RESULT_ERROR,message:l.translate("File reader null result."),file:o,blockIndex:t,domException:i.error});var a=crypto.subtle.digest("SHA-256",s.target.result);r.disconnectRuntime(),a.then((function(r){var i=(function(e){return e.replace(/\//g,"_").replace(/\+/g,"-")})(btoa(String.fromCharCode.apply(null,new Uint8Array(r))));if(!(i=(function(e){for(;e.endsWith("=");)e=e.slice(0,-1);return e})(i))&&!g)return u(),void n.trigger("Error",{code:l.CLIENT_HASH_EMPTY_ERROR,message:l.translate("Client hash empty or undefined error."),file:o});S[t]=i,t++,o.loaded+=1e4,n.trigger("UploadProgress",o,!1),t>=h?(o.loaded=0,m()):e(t)})).catch((function(e){if(!g)return u(),void n.trigger("Error",{code:l.CLIENT_HASH_DIGEST_ERROR,message:l.translate(e),file:o,blockIndex:t})}))};var a=r.getSource();i.readAsArrayBuffer(a)})(0)):A()}else n.trigger("Error",{code:l.CHUNKS_NOT_ENABLED_ERROR,message:l.translate("Chunks not enabled error."),file:o})}else n.trigger("Error",{code:l.BLOB_EMPTY_ERROR,message:l.translate("Blob size is 0 bytes."),file:o})}else n.trigger("Error",{code:l.BLOB_MISSING_ERROR,message:l.translate("Blob is missing."),file:o});function z(e){var t;if(r<=R)t=d;else{var i=e*R,s=Math.min(R,r-i);t=d.slice(i,i+s)}return t&&0!==t.size?t:(u(),void n.trigger("Error",{code:l.BLOCK_EMPTY_ERROR,message:l.translate("Block is empty."),file:o,blockIndex:e}))}function w(){return b===h&&y.length===h&&!y.includes(void 0)}function A(){for(var e=0;e<6&&e<h;e++)c=e,P(e)}function D(e,t){if(!(507!==t.status&&O[e]<n.settings.max_retries))return o.loaded=0,u(),void n.trigger("Error",{code:l.UPLOAD_BLOCK_ERROR,message:l.translate("Upload block HTTP error."),file:o,response:t.responseText,status:t.status,responseHeaders:t.getAllResponseHeaders()});i((function(){P(e)}),2e3),O[e]++}function P(e){var r=z(e),i=new t.XMLHttpRequest;i.withCredentials=!0;var s={};n.settings.multipart_params.file_request?s.owner_id=n.settings.multipart_params.owner_id:(s.owner_id=n.settings.multipart_params._subject_uid,s._subject_uid=n.settings.multipart_params._subject_uid),s.t=n.settings.multipart_params.t,s.reported_block_size=r.size,s.num_blocks=h,s.ns_id_for_routing=n.settings.multipart_params.ns_id_for_routing;var a=0;i.upload?i.upload.onprogress=function(e){e.loaded&&(o.loaded+=e.loaded-a,a=e.loaded,n.trigger("UploadProgress",o,!0))}:i.onreadystatechange=function(){i.readyState===XMLHttpRequest.DONE&&200===i.status&&(o.loaded+=r.size,n.trigger("UploadProgress",o,!0))},i.onload=function(){if(i.status>=400)D(e,i);else{var t,r,s;try{r=(t=JSON.parse(i.response)).block_hash,s=t.token}catch(t){return u(),void n.trigger("Error",{code:l.SERVER_RESPONSE_ERROR,message:l.translate("Server response error."),file:o,blockIndex:e})}if(!r)return u(),void n.trigger("Error",{code:l.SERVER_HASH_EMPTY_ERROR,message:l.translate("Server hash empty or undefined error."),file:o,blockIndex:e});if(!s)return u(),void n.trigger("Error",{code:l.SERVER_TOKEN_EMPTY_ERROR,message:l.translate("Server token empty or undefined error."),file:o,blockIndex:e});if(E){if(r!==S[e])return u(),void n.trigger("Error",{code:l.HASHES_NOT_EQUAL_ERROR,message:l.translate("Client and server hashes not equal error."),file:o,blockIndex:e});y[e]=s,b++,delete _[e]}else y[e]=s,b++,delete _[e];if(c<I)P(++c);else{if(c>I)return u(),void n.trigger("Error",{code:l.BLOCK_INDEX_ERROR,message:l.translate("Block index error."),file:o,blockIndex:e});if(w())n.settings.parallel_commit_and_upload&&(n.trigger("FileBlocksUploaded",o),o.status=l.COMMITTING),N(y);else if(c===I&&!Object.keys(_).length&&!w())return u(),void n.trigger("Error",{code:l.COMMIT_READINESS_ERROR,message:l.translate("Done iterating over blocks, but no requests in progress or outstanding and not ready to commit."),file:o})}}},i.onerror=function(){D(e,i)},i.onloadend=function(){delete _[e],this.destroy(),i=null},f=l.buildUrl(n.settings.waterfall_upload_block_url,s),i.open("post",f,!0),i.setRequestHeader("Content-Type","application/octet-stream"),l.each(n.settings.headers,(function(e,t){i.setRequestHeader(t,e)})),_[e]=i,i.send(r),O[e]++}function M(e,t){x(t,e.responseText,e.status,e.getAllResponseHeaders())}function x(e,t,r,s){if(!(507!==r&&v<n.settings.max_retries))return o.loaded=0,a(_),_={},void n.trigger("Error",{code:l.COMMIT_HTTP_ERROR,message:l.translate("Commit HTTP error."),file:o,response:t,status:r,responseHeaders:s});i((function(){N(e)}),8e3),v++}function C(e,t,r){o.size!=o.origSize&&(d.destroy(),d=null),n.trigger("UploadProgress",o,!0),o.status=l.DONE,n.trigger("FileUploaded",o,{response:e,status:t,responseHeaders:r}),_={}}function N(e){if("function"==typeof n.settings.send_commit_request)return n.settings.send_commit_request(n,o,e).then((function(e){C()})).catch((function(t){t.raw?x(e,t.raw.responseBody,t.raw.status):x(e)})),void v++;var r=new t.XMLHttpRequest;r.withCredentials=!0;var i={};if(n.settings.multipart_params.file_request?(i.ut=n.settings.multipart_params.ut,i.token=n.settings.multipart_params.token,i.submitted_email=n.settings.multipart_params.submitted_email,i.submitted_user_name=n.settings.multipart_params.submitted_user_name,i.user_id=n.settings.multipart_params.owner_id,i.dest=o.dest):(i._subject_uid=n.settings.multipart_params._subject_uid,i.dest=n.settings.multipart_params.dest,i.overwrite=n.settings.multipart_params.overwrite),i.reported_total_size=n.settings.multipart_params.reported_total_size,i.name=o.target_name||o.name,i.t=n.settings.multipart_params.t,r.onload=function(){var t;r.status>=400?M(r,e):r.readyState===XMLHttpRequest.DONE&&200===r.status&&C((t=r).responseText,t.status,t.getAllResponseHeaders())},r.onerror=function(){M(r,e)},r.onloadend=function(){_={},this.destroy(),r=null},f=l.buildUrl(n.settings.waterfall_commit_upload_url,i),r.open("post",f,!0),r.setRequestHeader("Content-Type","application/octet-stream"),l.each(n.settings.headers,(function(e,t){r.setRequestHeader(t,e)})),_.commitRequest=r,1!==Object.keys(_).length||!_.hasOwnProperty("commitRequest"))return u(),void n.trigger("Error",{code:l.COMMIT_READINESS_ERROR,message:l.translate("In commitFile call, but more than 1 request in progress or requestsInProgress map lacks the commit request."),file:o});r.send(JSON.stringify(e)),v++}}o.loaded&&(h=o.loaded=R*Math.floor(o.loaded/R)),d=o.getSource(),!t.isEmptyObj(n.settings.resize)&&(function(e,r){if(e.ruid){var i=t.Runtime.getInfo(e.ruid);if(i)return i.can(r)}return!1})(d,"send_binary_string")&&~t.inArray(d.type,["image/jpeg","image/png"])?v.call(this,d,n.settings.resize,(function(e){d=e,o.size=e.size,r.waterfall_parallel_uploads?S():O()})):r.waterfall_parallel_uploads?S():O()})),n.bind("UploadProgress",(function(e,t,r){h(t)})),n.bind("StateChanged",(function(e){if(e.state==l.STARTED)o=+new Date;else if(e.state==l.STOPPED)for(var t=e.files.length-1;t>=0;t--)e.files[t].status==l.UPLOADING&&(e.files[t].status=l.QUEUED,b())})),n.bind("QueueChanged",b),n.bind("Error",(function(e,t){t.file&&(t.file.status=l.FAILED,h(t.file),e.state==l.STARTED&&i((function(){E.call(n)}),1))}));const d=function(){b(),i((function(){E.call(n)}),1)};n.settings.parallel_commit_and_upload?n.bind("FileBlocksUploaded",d):n.bind("FileUploaded",d),n.trigger("Init",{runtime:this.runtime}),O.call(this)},refresh:function(){u&&u.trigger("Refresh"),this.trigger("Refresh")},start:function(){this.state!=l.STARTED&&(this.state=l.STARTED,this.trigger("StateChanged"),E.call(this))},stop:function(){this.state!=l.STOPPED&&(this.state=l.STOPPED,this.trigger("StateChanged"),this.trigger("CancelUpload"))},disableBrowse:function(){R=void 0===arguments[0]||arguments[0],u&&u.disable(R),this.trigger("DisableBrowse",R)},getFile:function(e){var t;for(t=f.length-1;t>=0;t--)if(f[t].id===e)return f[t]},addFile:function(e,r){var s,o,a=this,c=[],f=[];s=!!(o=d||u)&&o.getRuntime().uid,(function e(o){var u=t.typeOf(o);if(o instanceof t.File){if(!o.ruid&&!o.isDetached()){if(!s)return!1;o.ruid=s,o.connectRuntime(s)}const t=new l.File(o);t.batchId=o.batchId,t.chooserType=o.chooserType,e(t)}else if(o instanceof t.Blob)e(o.getSource()),o.destroy();else if(o instanceof l.File)r&&(o.dest=r),c.push((function(e){(function(e,r){var i=[];t.each(a.settings.filters,(function(t,r){n[r]&&i.push((function(i){n[r].call(a,t,e,(function(e){i(!e)}))}))})),t.inSeries(i,r)})(o,(function(t){t||f.push(o),i(e,1)}))}));else if(-1!==t.inArray(u,["file","blob"])){const r=new t.File(null,o);r.batchId=o.batchId,r.chooserType=o.chooserType,e(r)}else"node"===u&&"filelist"===t.typeOf(o.files)?t.each(o.files,e):"array"===u&&t.each(o,e)})(e),c.length&&t.inSeries(c,(function(){f.length&&a.trigger("FilesAdded",f)}))},removeFile:function(e){for(var t="string"==typeof e?e:e.id,r=f.length-1;r>=0;r--)if(f[r].id===t)return this.splice(r,1)[0]},renameFile:function(e,t){for(var r="string"==typeof e?e:e.id,i=f.length-1;i>=0;i--)if(f[i].id===r)return f[i].name=t,void(f[i].dest=t)},splice:function(e,t){var r=f.splice(void 0===e?0:e,void 0===t?f.length:t);return this.trigger("FilesRemoved",r),this.trigger("QueueChanged"),l.each(r,(function(e){e.destroy()})),r},trigger:function(e){var t,r,i=p[e.toLowerCase()];if(i)for((r=Array.prototype.slice.call(arguments))[0]=this,t=0;t<i.length;t++)if(!1===i[t].func.apply(i[t].scope,r))return!1;return!0},hasEventListener:function(e){return!!p[e.toLowerCase()]},bind:function(e,t,r){var i;e=e.toLowerCase(),(i=p[e]||[]).push({func:t,scope:r||this}),p[e]=i},unbind:function(e){e=e.toLowerCase();var t,r=p[e],i=arguments[1];if(r){if(void 0!==i){for(t=r.length-1;t>=0;t--)if(r[t].func===i){r.splice(t,1);break}}else r=[];r.length||delete p[e]}},unbindAll:function(){var e=this;l.each(p,(function(t,r){e.unbind(r)}))},destroy:function(){this.stop(),l.each(f,(function(e){e.destroy()})),f=[],u&&(u.destroy(),u=null),d&&(d.destroy(),d=null),m={},o=a=R=c=null,this.trigger("Destroy"),this.unbindAll(),p={}}})},l.File=(a={},function(e){l.extend(this,{id:l.guid(),name:e.name||e.fileName,dest:"",type:e.type||"",size:e.size||e.fileSize,origSize:e.size||e.fileSize,loaded:0,percent:0,status:l.QUEUED,lastModifiedDate:e.lastModifiedDate||(new Date).toLocaleString(),getNative:function(){var e=this.getSource().getSource();return-1!==t.inArray(t.typeOf(e),["blob","file"])?e:null},getSource:function(){return a[this.id]?a[this.id]:null},destroy:function(){var e=this.getSource();e&&(e.destroy(),delete a[this.id])}}),a[this.id]=e}),l.QueueProgress=function(){var e=this;e.size=0,e.loaded=0,e.uploaded=0,e.failed=0,e.queued=0,e.percent=0,e.bytesPerSec=0,e.reset=function(){e.size=e.loaded=e.uploaded=e.failed=e.queued=e.percent=e.bytesPerSec=0}},e.plupload=l})(window,i),e.exports=window.plupload},0:
/*!*************************************!*\
  !*** multi ./plupload_dev-2.0.0.js ***!
  \*************************************/
/*! no static exports found */function(e,t,r){e.exports=r(/*! ./plupload_dev-2.0.0.js */"./plupload_dev-2.0.0.js")},mOxie:
/*!************************!*\
  !*** external "mOxie" ***!
  \************************/
/*! no static exports found */function(t,r){t.exports=e}})}));
//# sourceMappingURL=plupload_dev.webpack.min.js-vflzuQ_rH.map