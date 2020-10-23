define(["require","exports","modules/clean/react/file_viewer/open_button/utils","modules/clean/cloud_docs/open_with_utils","modules/clean/cloud_docs/event_logging"],(function(e,n,o,i,r){"use strict";Object.defineProperty(n,"__esModule",{value:!0});var l=Object.freeze({local_path:null,resolved_local_path:null,is_locally_available:!1,can_open_directly:!1,open_application_identifier:null,open_application_name:null,path_is_dir:!1,is_infinite_placeholder:!1,error_message:null});n.getOpenOptionsForFile=function(e){var n=r.getActionSourceFromSurface(e.surface),a=e.sharingServiceInfo||{},t=e.isCloudEditorDisabled,s=t;return t||(t=!!e.cloudDocsInfo&&!e.cloudDocsInfo.openWithGddSupported,s=!!e.isOpenWithDisabled),o.getOpenOptions({file:e.file,hasOpenInPaperSupport:!!e.hasOpenInPaperSupport||!1,isOpenWithDisabled:!!s,unityInfo:e.unityInfo||l,extraOptions:e.extraOptions,user:e.user,sharingServiceInfo:a,refreshSharingServiceInfo:e.refreshSharingServiceInfo,showOpenWithShare:!1,onPresentInZoom:e.onPresentInZoom,isCloudBasedDoc:i.isCloudBasedDoc(e.file),actionSource:n,isCloudEditorDisabled:t,landingPagesEnabled:e.landingPagesEnabled})},n.getCategoryIdToInfos=function(e){var n={};return e.forEach((function(e){n[e.id]=e})),n}}));
//# sourceMappingURL=extensions_utils.min.js-vfl0z9gl5.map