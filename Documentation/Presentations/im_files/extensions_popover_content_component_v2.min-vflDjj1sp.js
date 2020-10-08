define(["require","exports","tslib","react","dig-components/menu","dig-components/icons","dig-components/icons/src","modules/clean/file_store/utils","modules/clean/react/app_actions/redirect","modules/clean/react/css","modules/clean/react/extensions/cloud_docs_compat","modules/clean/react/extensions/common","modules/clean/react/extensions/data/helpers","modules/clean/react/extensions/extensions_scaling_modal","modules/clean/react/extensions/menu_survey","modules/clean/react/extensions/unity_and_cloud_editors","modules/clean/react/file_viewer/constants","modules/clean/react/file_viewer/open_button/types","modules/clean/react/file_viewer/unity/with_unity","modules/clean/static_urls","modules/core/i18n"],(function(e,t,n,i,o,s,r,a,c,l,u,d,p,m,f,_,g,A,y,h,E){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var v=(function(e){function t(t){var s=e.call(this,t)||this;return s.createAppActionClickHandler=function(e){return function(){var t=s.props,i=t.file,o=t.user,r=t.featureFlags,a=t.telemetryContext,l=t.updateLinkState;if(c.redirectToActionOrShowAuth(o,i,e,r,a,l),"redirect"===e.handler[".tag"]){var p=d.getAppActionExtras(e);d.logEvent(s.props.currentSession,"select_action",n.__assign({menu_version:2},p))}else if("cloud_editor"===e.handler[".tag"]){var m=u.isWopiAction(e)?A.OpenButtonAction.OPEN_WITH:A.OpenButtonAction.OPEN_WITH_CLOUD_DOC;d.logEvent(s.props.currentSession,"select_legacy_action",{type:m})}}},s.wrapperForAction=function(e){return{appAction:e,handler:s.createAppActionClickHandler(e),userAction:g.UserAction.OpenWithAppAction,actionName:e.description}},s.renderActionRow=function(e){var t,n=e.icon;t=n.is_static?h.static_url("/static/images/generic_app_icon-vflIPYT1H.png"):n.url;var r=e.description;return i.default.createElement(o.Menu.ActionItem,{key:e.id,value:s.wrapperForAction(e),withLeftAccessory:i.default.createElement("img",{alt:"",src:t,width:24})},r)},s}return n.__extends(t,e),t.prototype.render=function(){var e=this,t=this.props,a=t.user,c=t.file,l=t.appActions,u=t.openOptions,g=t.bylines,A=t.categoryIdToInfos,y=t.featureFlags,h=t.currentSession,v=t.telemetryContext,O=t.updateLinkState,w=d.getOpenOptionsWithLogging(u,h),x=p.partitionOptions(w),M=x.unityOptions,C=x.cloudEditorOptions,S=p.partitionActions(l),I=S.cloudEditors,F=S.installedActions,U=S.unpromotedActions,W=F.length>0,k=U.length>0;return i.default.createElement(i.default.Fragment,null,i.default.createElement(_.UnityAndCloudEditors,{unityOptions:M,legacyCloudEditorOptions:C,cloudEditorAppActions:I.map((function(t){return e.wrapperForAction(t)})),bylines:g,currentSession:h}),W&&i.default.createElement(o.Menu.Segment,{key:"installed-actions"},F.map((function(t){return e.renderActionRow(t)}))),k&&i.default.createElement(o.Menu.Segment,null,i.default.createElement(o.Menu.ActionItem,{key:E.intl.formatMessage({id:"R/67N/",defaultMessage:"Show more"}),value:{handler:function(){var e=n.__spreadArrays(F,U);m.showExtensionsScalingModal(E.intl.formatMessage({id:"KVD2SP",defaultMessage:"Open or edit with these apps"}),a,c,e,A,y,O,v,h),d.logEvent(h,W?"select_show_more":"select_add_app",{surface:v&&v.surface})}},withLeftAccessory:W?null:i.default.createElement(s.UIIcon,{src:r.AddCircleLine})},W?E.intl.formatMessage({id:"Gevpqz",defaultMessage:"Connect more apps"}):E.intl.formatMessage({id:"XFA09U",defaultMessage:"Connect apps"}))),i.default.createElement(f.OpenMenuSurvey,{userId:a.id,session:h}))},t})((i=n.__importDefault(i)).default.Component);t.ExtensionsPopoverV2WithUnity=function(e){return a.isBrowseFile(e.file)?i.default.createElement(y.WithUnity,{file:e.file,user:e.user,render:function(t){return i.default.createElement(v,n.__assign({},e,{unityInfo:t}))}}):null},t.ExtensionsPopoverV2NoUnity=l.requireCssWithComponent(v,["/static/css/app_actions/index-vflHsvf3d.css","/static/css/extensions/index-vflRLfsLb.css"])}));
//# sourceMappingURL=extensions_popover_content_component_v2.min.js-vflsUeYYE.map