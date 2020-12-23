define("dropbox/proto/js_init_data/chat/chat",["require","exports","tslib","protobufjs-dbx/minimal"],(function(e,t,a,n){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var i,r,o,s=(n=a.__importStar(n)).Reader,c=n.Writer,p=n.util,u=n.roots.default||(n.roots.default={});t.default=u,t.chat=u.chat=((i=u.chat||{}).ChatProviderType=(r={},(o=Object.create(r))[r[0]="SNAPENGAGE"]=0,o),i.ProactiveMessageType=(function(){var e={},t=Object.create(e);return t[e[0]="DEFAULT"]=0,t[e[1]="MINIMIZED_PROACTIVE"]=1,t})(),i.ChatInitialState=(function(){var e={},t=Object.create(e);return t[e[0]="HIDDEN"]=0,t[e[1]="SHOW_PROVIDER_REACTIVE_BUTTON"]=1,t})(),i.ChatMetadata=(function(e){function e(e){if(e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}return e.prototype.cookieDomain="",e.prototype.cookieCampaignName="",e.prototype.legacyCookieCampaignName="",e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.cookieDomain&&Object.hasOwnProperty.call(e,"cookieDomain")&&t.uint32(10).string(e.cookieDomain),null!=e.cookieCampaignName&&Object.hasOwnProperty.call(e,"cookieCampaignName")&&t.uint32(18).string(e.cookieCampaignName),null!=e.legacyCookieCampaignName&&Object.hasOwnProperty.call(e,"legacyCookieCampaignName")&&t.uint32(26).string(e.legacyCookieCampaignName),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a=void 0===t?e.len:e.pos+t,n=new u.chat.ChatMetadata;e.pos<a;){var i=e.uint32();switch(i>>>3){case 1:n.cookieDomain=e.string();break;case 2:n.cookieCampaignName=e.string();break;case 3:n.legacyCookieCampaignName=e.string();break;default:e.skipType(7&i)}}return n},e})(i.ChatMetadata||{}),i.SnapengageChatMetadata=(function(e){function e(e){if(e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}return e.prototype.snapengageIframeOrigin="",e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.snapengageIframeOrigin&&Object.hasOwnProperty.call(e,"snapengageIframeOrigin")&&t.uint32(34).string(e.snapengageIframeOrigin),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a=void 0===t?e.len:e.pos+t,n=new u.chat.SnapengageChatMetadata;e.pos<a;){var i=e.uint32();switch(i>>>3){case 4:n.snapengageIframeOrigin=e.string();break;default:e.skipType(7&i)}}return n},e})(i.SnapengageChatMetadata||{}),i.UserProperties=(function(e){function e(e){if(this.pricings=[],this.experiments={},e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}return e.prototype.chatHmac="",e.prototype.email="",e.prototype.firstName="",e.prototype.lastName="",e.prototype.pageLoadTs="",e.prototype.pricings=p.emptyArray,e.prototype.sessionId="",e.prototype.userId="",e.prototype.serviceTier="",e.prototype.experiments=p.emptyObject,e.prototype.locale="",e.prototype.countryCode="",e.create=function(t){return new e(t)},e.encode=function(e,t){if(t||(t=c.create()),null!=e.chatHmac&&Object.hasOwnProperty.call(e,"chatHmac")&&t.uint32(10).string(e.chatHmac),null!=e.email&&Object.hasOwnProperty.call(e,"email")&&t.uint32(18).string(e.email),null!=e.firstName&&Object.hasOwnProperty.call(e,"firstName")&&t.uint32(26).string(e.firstName),null!=e.lastName&&Object.hasOwnProperty.call(e,"lastName")&&t.uint32(34).string(e.lastName),null!=e.pageLoadTs&&Object.hasOwnProperty.call(e,"pageLoadTs")&&t.uint32(42).string(e.pageLoadTs),null!=e.pricings&&e.pricings.length)for(var a=0;a<e.pricings.length;++a)t.uint32(50).string(e.pricings[a]);if(null!=e.sessionId&&Object.hasOwnProperty.call(e,"sessionId")&&t.uint32(58).string(e.sessionId),null!=e.userId&&Object.hasOwnProperty.call(e,"userId")&&t.uint32(66).string(e.userId),null!=e.serviceTier&&Object.hasOwnProperty.call(e,"serviceTier")&&t.uint32(74).string(e.serviceTier),null!=e.experiments&&Object.hasOwnProperty.call(e,"experiments")){var n=Object.keys(e.experiments);for(a=0;a<n.length;++a)t.uint32(82).fork().uint32(10).string(n[a]).uint32(18).string(e.experiments[n[a]]).ldelim()}return null!=e.locale&&Object.hasOwnProperty.call(e,"locale")&&t.uint32(90).string(e.locale),null!=e.countryCode&&Object.hasOwnProperty.call(e,"countryCode")&&t.uint32(98).string(e.countryCode),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a,n=void 0===t?e.len:e.pos+t,i=new u.chat.UserProperties;e.pos<n;){var r=e.uint32();switch(r>>>3){case 1:i.chatHmac=e.string();break;case 2:i.email=e.string();break;case 3:i.firstName=e.string();break;case 4:i.lastName=e.string();break;case 5:i.pageLoadTs=e.string();break;case 6:i.pricings&&i.pricings.length||(i.pricings=[]),i.pricings.push(e.string());break;case 7:i.sessionId=e.string();break;case 8:i.userId=e.string();break;case 9:i.serviceTier=e.string();break;case 10:e.skip().pos++,i.experiments===p.emptyObject&&(i.experiments={}),a=e.string(),e.pos++,i.experiments[a]=e.string();break;case 11:i.locale=e.string();break;case 12:i.countryCode=e.string();break;default:e.skipType(7&r)}}return i},e})(i.UserProperties||{}),i.SnapengageChatSystemSettings=(function(e){function e(e){if(e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}return e.prototype.widgetId="",e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.widgetId&&Object.hasOwnProperty.call(e,"widgetId")&&t.uint32(10).string(e.widgetId),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a=void 0===t?e.len:e.pos+t,n=new u.chat.SnapengageChatSystemSettings;e.pos<a;){var i=e.uint32();switch(i>>>3){case 1:n.widgetId=e.string();break;default:e.skipType(7&i)}}return n},e})(i.SnapengageChatSystemSettings||{}),i.ProactiveSettings=(function(e){function e(e){if(e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}return e.prototype.proactiveType=0,e.prototype.whenToShowControlledByProvider=!1,e.prototype.secondsUntilShown=p.Long?p.Long.fromBits(0,0,!0):0,e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.proactiveType&&Object.hasOwnProperty.call(e,"proactiveType")&&t.uint32(8).int32(e.proactiveType),null!=e.whenToShowControlledByProvider&&Object.hasOwnProperty.call(e,"whenToShowControlledByProvider")&&t.uint32(16).bool(e.whenToShowControlledByProvider),null!=e.secondsUntilShown&&Object.hasOwnProperty.call(e,"secondsUntilShown")&&t.uint32(24).uint64(e.secondsUntilShown),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a=void 0===t?e.len:e.pos+t,n=new u.chat.ProactiveSettings;e.pos<a;){var i=e.uint32();switch(i>>>3){case 1:n.proactiveType=e.int32();break;case 2:n.whenToShowControlledByProvider=e.bool();break;case 3:n.secondsUntilShown=e.uint64();break;default:e.skipType(7&i)}}return n},e})(i.ProactiveSettings||{}),i.CampaignResult=(function(e){function e(e){if(e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}var t;return e.prototype.campaignId=p.Long?p.Long.fromBits(0,0,!0):0,e.prototype.versionId=p.Long?p.Long.fromBits(0,0,!0):0,e.prototype.campaignName="",e.prototype.versionName="",e.prototype.snapengageChatSystemSettings=null,e.prototype.mustHaveAvailableAgents=!1,e.prototype.proactiveSettings=null,e.prototype.greetingMessage="",e.prototype.chatInitialState=0,e.prototype.persistenceCookie="",e.prototype.deprecatedExperimentNameToLog="",e.prototype.deprecatedExperimentVariantToLog="",e.prototype.isControl=!1,Object.defineProperty(e.prototype,"systemSettings",{get:p.oneOfGetter(t=["snapengageChatSystemSettings"]),set:p.oneOfSetter(t)}),e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.campaignId&&Object.hasOwnProperty.call(e,"campaignId")&&t.uint32(8).uint64(e.campaignId),null!=e.versionId&&Object.hasOwnProperty.call(e,"versionId")&&t.uint32(16).uint64(e.versionId),null!=e.campaignName&&Object.hasOwnProperty.call(e,"campaignName")&&t.uint32(26).string(e.campaignName),null!=e.versionName&&Object.hasOwnProperty.call(e,"versionName")&&t.uint32(34).string(e.versionName),null!=e.snapengageChatSystemSettings&&Object.hasOwnProperty.call(e,"snapengageChatSystemSettings")&&u.chat.SnapengageChatSystemSettings.encode(e.snapengageChatSystemSettings,t.uint32(42).fork()).ldelim(),null!=e.mustHaveAvailableAgents&&Object.hasOwnProperty.call(e,"mustHaveAvailableAgents")&&t.uint32(48).bool(e.mustHaveAvailableAgents),null!=e.proactiveSettings&&Object.hasOwnProperty.call(e,"proactiveSettings")&&u.chat.ProactiveSettings.encode(e.proactiveSettings,t.uint32(58).fork()).ldelim(),null!=e.greetingMessage&&Object.hasOwnProperty.call(e,"greetingMessage")&&t.uint32(66).string(e.greetingMessage),null!=e.chatInitialState&&Object.hasOwnProperty.call(e,"chatInitialState")&&t.uint32(72).int32(e.chatInitialState),null!=e.persistenceCookie&&Object.hasOwnProperty.call(e,"persistenceCookie")&&t.uint32(82).string(e.persistenceCookie),null!=e.deprecatedExperimentNameToLog&&Object.hasOwnProperty.call(e,"deprecatedExperimentNameToLog")&&t.uint32(90).string(e.deprecatedExperimentNameToLog),null!=e.deprecatedExperimentVariantToLog&&Object.hasOwnProperty.call(e,"deprecatedExperimentVariantToLog")&&t.uint32(98).string(e.deprecatedExperimentVariantToLog),null!=e.isControl&&Object.hasOwnProperty.call(e,"isControl")&&t.uint32(104).bool(e.isControl),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a=void 0===t?e.len:e.pos+t,n=new u.chat.CampaignResult;e.pos<a;){var i=e.uint32();switch(i>>>3){case 1:n.campaignId=e.uint64();break;case 2:n.versionId=e.uint64();break;case 3:n.campaignName=e.string();break;case 4:n.versionName=e.string();break;case 5:n.snapengageChatSystemSettings=u.chat.SnapengageChatSystemSettings.decode(e,e.uint32());break;case 6:n.mustHaveAvailableAgents=e.bool();break;case 7:n.proactiveSettings=u.chat.ProactiveSettings.decode(e,e.uint32());break;case 8:n.greetingMessage=e.string();break;case 9:n.chatInitialState=e.int32();break;case 10:n.persistenceCookie=e.string();break;case 11:n.deprecatedExperimentNameToLog=e.string();break;case 12:n.deprecatedExperimentVariantToLog=e.string();break;case 13:n.isControl=e.bool();break;default:e.skipType(7&i)}}return n},e})(i.CampaignResult||{}),i.ChatInitializerProperties=(function(e){function e(e){if(e)for(var t=Object.keys(e),a=0;a<t.length;++a)null!=e[t[a]]&&(this[t[a]]=e[t[a]])}var t;return e.prototype.chatMetadata=null,e.prototype.userProperties=null,e.prototype.campaignResult=null,e.prototype.resume=!1,e.prototype.chatProviderType=0,e.prototype.snapengageChatMetadata=null,e.prototype.loggingCorrelationId="",Object.defineProperty(e.prototype,"chatProviderMetadata",{get:p.oneOfGetter(t=["snapengageChatMetadata"]),set:p.oneOfSetter(t)}),e.create=function(t){return new e(t)},e.encode=function(e,t){return t||(t=c.create()),null!=e.chatMetadata&&Object.hasOwnProperty.call(e,"chatMetadata")&&u.chat.ChatMetadata.encode(e.chatMetadata,t.uint32(10).fork()).ldelim(),null!=e.userProperties&&Object.hasOwnProperty.call(e,"userProperties")&&u.chat.UserProperties.encode(e.userProperties,t.uint32(18).fork()).ldelim(),null!=e.campaignResult&&Object.hasOwnProperty.call(e,"campaignResult")&&u.chat.CampaignResult.encode(e.campaignResult,t.uint32(26).fork()).ldelim(),null!=e.resume&&Object.hasOwnProperty.call(e,"resume")&&t.uint32(32).bool(e.resume),null!=e.chatProviderType&&Object.hasOwnProperty.call(e,"chatProviderType")&&t.uint32(40).int32(e.chatProviderType),null!=e.snapengageChatMetadata&&Object.hasOwnProperty.call(e,"snapengageChatMetadata")&&u.chat.SnapengageChatMetadata.encode(e.snapengageChatMetadata,t.uint32(50).fork()).ldelim(),null!=e.loggingCorrelationId&&Object.hasOwnProperty.call(e,"loggingCorrelationId")&&t.uint32(58).string(e.loggingCorrelationId),t},e.decode=function(e,t){e instanceof s||(e=s.create(e));for(var a=void 0===t?e.len:e.pos+t,n=new u.chat.ChatInitializerProperties;e.pos<a;){var i=e.uint32();switch(i>>>3){case 1:n.chatMetadata=u.chat.ChatMetadata.decode(e,e.uint32());break;case 2:n.userProperties=u.chat.UserProperties.decode(e,e.uint32());break;case 3:n.campaignResult=u.chat.CampaignResult.decode(e,e.uint32());break;case 4:n.resume=e.bool();break;case 5:n.chatProviderType=e.int32();break;case 6:n.snapengageChatMetadata=u.chat.SnapengageChatMetadata.decode(e,e.uint32());break;case 7:n.loggingCorrelationId=e.string();break;default:e.skipType(7&i)}}return n},e})(i.ChatInitializerProperties||{}),i)})),define("modules/clean/chat/chat_client",["require","exports","tslib","dropbox/proto/js_init_data/chat/chat","modules/core/cookies","modules/clean/chat/chat_identifier","modules/clean/chat/chat_provider_api","modules/clean/chat/chat_client_api","modules/clean/chat/chat_provider_factory","proto_utils/unpack","modules/core/browser","modules/clean/analytics","modules/clean/amp_web_logger","modules/clean/ncct/manual_assist_util","modules/clean/ajax","modules/clean/stormcrow/stormcrow_exposure_logger"],(function(e,t,a,n,i,r,o,s,c,p,u,d,g,h,l,C){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),u=a.__importStar(u);var m,S;(function(e){e[e.NOT_SHOWN=0]="NOT_SHOWN",e[e.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_LOAD=1]="TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_LOAD",e[e.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_AGENT_STATUS_UPDATE=2]="TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_AGENT_STATUS_UPDATE",e[e.REQUESTED_PROVIDER_TO_SHOW_REACTIVE_BUTTON=3]="REQUESTED_PROVIDER_TO_SHOW_REACTIVE_BUTTON",e[e.SHOWING_PROVIDER_REACTIVE_BUTTON=4]="SHOWING_PROVIDER_REACTIVE_BUTTON",e[e.SHOWING_CHAT=5]="SHOWING_CHAT",e[e.TO_START_ON_LOAD=6]="TO_START_ON_LOAD",e[e.TO_START_ON_AGENT_STATUS_UPDATE=7]="TO_START_ON_AGENT_STATUS_UPDATE",e[e.REQUESTED_PROVIDER_TO_START_CHAT=8]="REQUESTED_PROVIDER_TO_START_CHAT",e[e.CHAT_ONGOING=9]="CHAT_ONGOING"})(m||(m={})),(function(e){e[e.REACTIVE=0]="REACTIVE",e[e.PROACTIVE=1]="PROACTIVE",e[e.RESUME=2]="RESUME"})(S||(S={}));var f=(function(e){function t(t,a){var s=e.call(this,t,a)||this;return s.setupChatEnvironment=function(e){if(s.shouldAllowChat()&&!s._isSetup){if(s.setupTime=new Date,s.hasFirstLoadOccured=!1,s.state={lifecycleState:m.NOT_SHOWN,hasShownAChat:!1},!e.chatMetadata)throw new Error("Did not provide chat metadata.");if(s.metadata=e.chatMetadata,!e.userProperties)throw new Error("Did not provide user properties.");var t;if("snapengageChatMetadata"!==e.chatProviderMetadata)throw new Error("No provider metadata provided");t=e.snapengageChatMetadata;var a=e.campaignResult;if(a&&a.isControl)s.setupControlLogging(a),s.setupProvider(void 0,t,e.userProperties,e.chatProviderType);else{a&&(s.chatCampaignWrapper={chatCampaign:a,chatCampaignState:s.getInitialChatCampaignState()}),s.setupProvider(a,t,e.userProperties,e.chatProviderType),s.setupProactivePropertiesIfNeeded();var i=a&&a.chatInitialState===n.chat.ChatInitialState.SHOW_PROVIDER_REACTIVE_BUTTON;if(e.resume){var o=s.chatCampaignWrapper||s.defaultChatWrapper;s.deprecatedLogChatAction("chat_persistence",r.getSnapengageWidgetId(o.chatCampaign)),s.intializeStartingChat(o,S.RESUME)}else i&&(s.attemptToShowProviderReactiveChatButton(),s.deprecatedMaybeLogExperiment(a))}}},s.startReactiveChat=function(){if(s.shouldAllowChat()){if(!s._isSetup)throw new Error("Started chat without being initalized");if(s.canStartChat()){var e=s.chatCampaignWrapper;if(!s.chatCampaignWrapper)return e=s.defaultChatWrapper,s.deprecatedLogChatAction("chat_initiated",r.getSnapengageWidgetId(e.chatCampaign)),void s.intializeStartingChat(e,S.REACTIVE);s.deprecatedLogChatAction("chat_initiated",r.getSnapengageWidgetId(e.chatCampaign)),s.intializeStartingChat(s.chatCampaignWrapper,S.REACTIVE)}}},s.startSupportChat=function(e){if(s.shouldAllowChat()){if(!s._isSetup)throw new Error("Started chat without being initialized");s.canStartChat()&&(s.supportChatWrapper={chatCampaign:e,chatCampaignState:s.getInitialChatCampaignState()},h.isNCCTChat(e)&&l.WebRequest({url:"/team/admin/engaged_chat",data:{chatId:e}}),s.deprecatedLogChatAction("support_chat_initiated",e),s.intializeStartingChat(s.supportChatWrapper,S.REACTIVE))}},s.isSetup=function(){return s._isSetup},s.setupProvider=function(e,t,a,n){var i={chatCampaign:e,metadata:t,userProperties:a,onAgentStatusUpdate:s.onAgentStatusUpdate,onChatLoadStatusUpdate:s.onChatLoadStatusUpdate,onChatShown:s.onChatShown,onChatStarted:s.onChatStarted,onChatClosed:s.onChatClosed,onProviderDrivenOpenProactive:s.onProviderDrivenOpenProactive,onProviderReactiveButtonShown:s.onProviderReactiveButtonShown};s.provider=s.getChatProvider(n,i),s.defaultChatWrapper={chatCampaign:s.provider.getDefaultChatIdentifier(),chatCampaignState:s.getInitialChatCampaignState()},s._isSetup=!0},s.attemptToShowProviderReactiveChatButton=function(){var e=s.chatCampaignWrapper;e&&r.isCampaignResult(e.chatCampaign)&&(s.state.campaign=e.chatCampaign,e.chatCampaignState.isLoaded?r.isCampaignResult(e.chatCampaign)&&e.chatCampaign.mustHaveAvailableAgents?s.attemptToShowReactiveButtonChatThatMustHaveAgents(e):s.requestProviderToShowProviderReactiveButton():s.requestProviderToLoadChatToShowProviderReactiveButton(e))},s.requestProviderToShowProviderReactiveButton=function(){s.state.lifecycleState=m.REQUESTED_PROVIDER_TO_SHOW_REACTIVE_BUTTON,s.provider.showProviderReactiveChatButton();var e=s.chatCampaignWrapper||s.defaultChatWrapper;s.deprecatedLogChatAction("minimized_chat_initiated",r.getSnapengageWidgetId(e.chatCampaign))},s.requestProviderToGetAgentStatusUpdateToShowProviderReactiveButton=function(e){s.state.lifecycleState=m.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_AGENT_STATUS_UPDATE,s.provider.requestAgentStatusUpdate(e.chatCampaign)},s.requestProviderToLoadChatToShowProviderReactiveButton=function(e){s.state.lifecycleState=m.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_LOAD,s.provider.requestAgentStatusUpdate(e.chatCampaign)},s.canStartChat=function(){var e=s.state.lifecycleState;return e===m.NOT_SHOWN||e===m.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_LOAD||e===m.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_AGENT_STATUS_UPDATE||e===m.REQUESTED_PROVIDER_TO_SHOW_REACTIVE_BUTTON||e===m.SHOWING_PROVIDER_REACTIVE_BUTTON},s.intializeStartingChat=function(e,t){s.state.source_type=t,s.state.campaign=e.chatCampaign,s.attemptToStartChat(e)},s.attemptToStartChat=function(e){var t=s.state.source_type,a=t===S.PROACTIVE;e.chatCampaignState.isLoaded?a&&r.isCampaignResult(e.chatCampaign)&&e.chatCampaign.mustHaveAvailableAgents?s.attemptToStartChatThatMustHaveAgents(e):s.requestProviderToStartChat(e):s.requestProviderToLoadChatToStartChat(e)},s.requestProviderToStartChat=function(e){s.state.lifecycleState=m.REQUESTED_PROVIDER_TO_START_CHAT,s.provider.startChat(e.chatCampaign)},s.requestProviderToGetAgentStatusUpdateToStartChat=function(e){s.state.lifecycleState=m.TO_START_ON_AGENT_STATUS_UPDATE,s.provider.requestAgentStatusUpdate(e.chatCampaign)},s.setupProactivePropertiesIfNeeded=function(){},s.setupControlLogging=function(e){var t=e.proactiveSettings;if(t){var a=1e3*t.secondsUntilShown;setTimeout((function(){return s.deprecatedMaybeLogExperiment(e)}),a)}},s.getPersistenceCookie=function(e){return r.isCampaignResult(e)?e.persistenceCookie:"SNAPENGAGE:"+e},s.setChatVisibleCookie=function(e){if(s.metadata){var t=s.getPersistenceCookie(e),a=s.getLegacyCampaignIdentifierToCookieStr(e);i.Cookies.create(s.metadata.cookieCampaignName,t,1,s.metadata.cookieDomain),i.Cookies.create(s.metadata.legacyCookieCampaignName,a,1,s.metadata.cookieDomain)}},s.getInitialChatCampaignState=function(){return{isLoaded:!1,agentStatus:o.AgentStatus.NOT_SET}},s.getWrapperFromIdentifier=function(e){return s.chatCampaignWrapper&&r.areChatCampaignsEqual(s.chatCampaignWrapper.chatCampaign,e)?s.chatCampaignWrapper:r.areChatCampaignsEqual(s.defaultChatWrapper.chatCampaign,e)?s.defaultChatWrapper:s.supportChatWrapper&&r.areChatCampaignsEqual(s.supportChatWrapper.chatCampaign,e)?s.supportChatWrapper:void 0},s.getLegacyCampaignIdentifierToCookieStr=function(e){return r.isCampaignResult(e)?e.snapengageChatSystemSettings.widgetId:e},s.onAgentStatusUpdate=function(e,t){var a=r.areChatCampaignsEqual(s.state.campaign,e),n=s.state.lifecycleState,i=n===m.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_AGENT_STATUS_UPDATE&&a,o=n===m.TO_START_ON_AGENT_STATUS_UPDATE&&a,c=s.getWrapperFromIdentifier(e);void 0!==c&&(c.chatCampaignState.agentStatus=t,i?s.attemptToShowProviderReactiveChatButton():o&&s.attemptToStartChat(c))},s.onChatLoadStatusUpdate=function(e,t){!s.hasFirstLoadOccured&&t&&(s.hasFirstLoadOccured=!0,s.deprecatedLogChatAction("snapengage_loaded",r.getSnapengageWidgetId(e),{total_time:(new Date).valueOf()-s.setupTime.valueOf()}));var a=r.areChatCampaignsEqual(s.state.campaign,e),n=s.state.lifecycleState,i=n===m.TO_SHOW_PROVIDER_REACTIVE_BUTTON_ON_LOAD&&a,o=n===m.TO_START_ON_LOAD&&a,c=s.getWrapperFromIdentifier(e);void 0!==c&&(c.chatCampaignState.isLoaded=t,i?s.attemptToShowProviderReactiveChatButton():o&&s.attemptToStartChat(c))},s.onProviderReactiveButtonShown=function(){s.state.lifecycleState===m.REQUESTED_PROVIDER_TO_SHOW_REACTIVE_BUTTON&&(s.state.lifecycleState=m.SHOWING_PROVIDER_REACTIVE_BUTTON)},s.onProviderDrivenOpenProactive=function(e){s.chatCampaignWrapper&&r.areChatCampaignsEqual(s.chatCampaignWrapper.chatCampaign,e)&&!s.state.hasShownAChat&&s.canStartChat()&&(s.deprecatedMaybeLogExperiment(e),s.intializeStartingChat(s.chatCampaignWrapper,S.PROACTIVE),s.deprecatedLogChatAction("proactive_chat_opened",r.getSnapengageWidgetId(e)))},s.onChatShown=function(e){s.state.lifecycleState!==m.SHOWING_PROVIDER_REACTIVE_BUTTON&&s.state.lifecycleState!==m.REQUESTED_PROVIDER_TO_START_CHAT||r.areChatCampaignsEqual(s.state.campaign,e),s.state.lifecycleState=m.SHOWING_CHAT,s.state.campaign=e,s.state.hasShownAChat=!0,s.state.source_type===S.RESUME&&s.provider.updateHmac()},s.onChatStarted=function(e){var t=s.state.source_type;if(void 0!==t){var a=void 0;t===S.RESUME?a="chat_persistence_init":t===S.PROACTIVE?(a="proactive_chat_initiated",h.isNCCTChat(r.getSnapengageWidgetId(e))&&l.WebRequest({url:"/team/admin/engaged_chat",data:{chatId:r.getSnapengageWidgetId(e)}})):t===S.REACTIVE&&(a="reactive_chat_initiated"),void 0!==a&&s.deprecatedLogChatAction(a,r.getSnapengageWidgetId(e))}s.setChatVisibleCookie(e),s.state.lifecycleState=m.CHAT_ONGOING},s.onChatClosed=function(e,t){s.handleCookieOnClosed();var a=void 0;void 0!==t.agentStatus&&(a=t.agentStatus===o.AgentStatus.ONLINE?"online":"offlline"),s.deprecatedLogChatAction("snapengage_chat_close",r.getSnapengageWidgetId(e),{type:t.chatType,agent_status:a}),s.resetChatState()},s.getChatProvider=t,s.shouldAllowChat=a,s._isSetup=!1,s}return a.__extends(t,e),t.prototype.attemptToShowReactiveButtonChatThatMustHaveAgents=function(e){var t=e.chatCampaignState.agentStatus;t===o.AgentStatus.NOT_SET?this.requestProviderToGetAgentStatusUpdateToShowProviderReactiveButton(e):t===o.AgentStatus.OFFLINE?(this.deprecatedLogChatAction("chat_agent_must_be_online_but_was_offline",r.getSnapengageWidgetId(e.chatCampaign)),this.resetChatState()):this.requestProviderToShowProviderReactiveButton()},t.prototype.attemptToStartChatThatMustHaveAgents=function(e){var t=e.chatCampaignState.agentStatus;t===o.AgentStatus.NOT_SET?this.requestProviderToGetAgentStatusUpdateToStartChat(e):t===o.AgentStatus.OFFLINE?this.resetChatState():this.requestProviderToStartChat(e)},t.prototype.requestProviderToLoadChatToStartChat=function(e){this.state.lifecycleState=m.TO_START_ON_LOAD,this.provider.loadChatIfNecessary(e.chatCampaign)},t.prototype.handleCookieOnClosed=function(){this.metadata&&(i.Cookies.delete(this.metadata.cookieCampaignName),i.Cookies.delete(this.metadata.legacyCookieCampaignName))},t.prototype.deprecatedLogChatAction=function(e,t,n){var i={chat_widget_id:t,url:u.get_href()},r=a.__assign(a.__assign({},i),n);d.TeamsWebActionsLogger.log(t,r),g.AMPWebLogger.logEventCount("chat_events",t,{chat_widget_id:t})},t.prototype.deprecatedMaybeLogExperiment=function(e){if(r.isCampaignResult(e)){var t=e.deprecatedExperimentNameToLog,a=e.deprecatedExperimentVariantToLog;if(t&&a)(new C.StormcrowExposureLogger).logExposure(t,a)}},t.prototype.resetChatState=function(){this.state.lifecycleState=m.NOT_SHOWN,this.state.campaign=void 0,this.state.source_type=void 0},t})(s.ChatClient);t._ChatClientSingleton=f;t.ChatClientSingleton=new f(c.ChatProviderFactorySingleton.getChatProvider,(function(){return top===window})),t.moduleInit=function(e){var a=p.unpackProto(e,n.chat.ChatInitializerProperties);t.ChatClientSingleton.setupChatEnvironment(a)}})),define("modules/clean/chat/chat_client_api",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var a=function(e,t){this.setupChatEnvironment=function(e){},this.startReactiveChat=function(){},this.startSupportChat=function(e){}};t.ChatClient=a})),define("modules/clean/chat/chat_client_factory",["require","exports","modules/clean/chat/chat_wrapper"],(function(e,t,a){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var n=function(){this.getClient=function(){return a.ChatWrapperSingleton}};t.ChatClientFactory=new n})),define("modules/clean/chat/chat_identifier",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.isCampaignResult=function(e){return void 0!==e.campaignId},t.isSnapengageWidgetId=function(e){return"string"==typeof e},t.areChatCampaignsEqual=function(e,a){return!!e&&(t.isCampaignResult(e)&&t.isCampaignResult(a)?e.campaignId===a.campaignId:!(!t.isSnapengageWidgetId(e)||!t.isSnapengageWidgetId(a))&&e===a)},t.getSnapengageWidgetId=function(e){return t.isCampaignResult(e)?e.snapengageChatSystemSettings.widgetId:e}})),define("modules/clean/chat/chat_provider_api",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),(function(e){e[e.NOT_SET=0]="NOT_SET",e[e.OFFLINE=1]="OFFLINE",e[e.ONLINE=2]="ONLINE"})(t.AgentStatus||(t.AgentStatus={}));var a=function(e){};t.ChatProvider=a})),define("modules/clean/chat/chat_provider_factory",["require","exports","dropbox/proto/js_init_data/chat/chat","modules/clean/chat/snapengage_chat_provider"],(function(e,t,a,n){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var i=function(){this.getChatProvider=function(e,t){if(e===a.chat.ChatProviderType.SNAPENGAGE)return new n.SnapengageChatProvider(t);throw new Error("Unknown chat provider type "+e)}};t.ChatProviderFactorySingleton=new i})),define("modules/clean/chat/chat_wrapper",["require","exports","modules/clean/chat/chat_client","modules/clean/snapengage"],(function(e,t,a,n){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var i=function(){var e=this;this.startReactiveChat=function(){e.getClient().startReactiveChat()},this.startSupportChat=function(t){var i=e.getClient();void 0===t?a.ChatClientSingleton.isSetup()?a.ChatClientSingleton.startReactiveChat():n.DropboxSnapEngage.startSupportChat(t):i.startSupportChat(t)},this.disableDropboxSnapEngageUpdateChatStatus=function(){n.DropboxSnapEngage.updateChatStatus=function(){}},this.getClient=function(){return a.ChatClientSingleton.isSetup()?a.ChatClientSingleton:n.DropboxSnapEngage}};t.ChatWrapper=i,t.ChatWrapperSingleton=new i})),define("modules/clean/chat/snapengage_chat_instance_handler",["require","exports","tslib","modules/clean/chat/chat_identifier","modules/clean/css","modules/core/browser","modules/core/uri","modules/core/i18n","modules/clean/chat/snapengage_tags","modules/clean/chat/snapengage_chat_instance_handler_api","modules/clean/chat/chat_provider_api"],(function(e,t,a,n,i,r,o,s,c,p,u){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=a.__importStar(r);var d=(function(e){function t(t){var a=e.call(this,t)||this;return a.isLoaded=function(){return a._isLoaded},a.requestAgentStatusUpdate=function(){a.checkChatStatus()},a.showReactiveButton=function(){a.showSnapEngageIframe(),a.minimizeSnapEngageIframe()},a.startChat=function(){a.showSnapEngageIframe(),a.sendMessage("startChatV2")},a.switchCampaign=function(e){a.chatCampaign=e,a.chatId=n.getSnapengageWidgetId(a.chatCampaign),a.sendMessage("switchCampaign")},a.updateHmac=function(){a.sendMessage("updateHmac")},a.initialize=function(){window.addEventListener("message",a.receiveMessage,!1),i.require_css("/static/css/business/components/snap_engage-vflfz1ZQW.css",(function(){a.createIframe()}))},a.createIframe=function(){var e=r.get_uri(),t=o.URI.parse(a.metadata.snapengageIframeOrigin);a.iframe=document.createElement("iframe"),e.setScheme(t.getScheme()),e.setAuthority(t.getAuthority()),a.iframe.src=e.toString(),a.iframe.setAttribute("sandbox","allow-scripts allow-same-origin allow-popups allow-forms"),a.iframe.setAttribute("class","snapengage-iframe"),a.iframe.setAttribute("id",a.iframeId),a.iframe.setAttribute("allowTransparency","true"),a.iframe.setAttribute("title",s.intl.formatMessage({id:"/nsbvt",defaultMessage:"Live chat box"})),a.iframe.setAttribute("tabindex","1"),a.iframe.addEventListener("load",a.handleIframeLoad),document.body.insertBefore(a.iframe,document.body.childNodes[0]),setInterval(a.checkChatStatus,13e4)},a.handleIframeLoad=function(){a.iFrameLeftStyle=a.iframe&&a.iframe.style.left,a.sendMessage("createSnapEngageScriptV2")},a.showSnapEngageIframe=function(e){void 0===e&&(e=!1),a.iframe&&(a.iframe.style.display="inline",a.iframe.style.left=a.iFrameLeftStyle,a.isVisible=!0)},a.onCloseChat=function(e){var t,n;a.iframe&&(a.iframe.style.display="none"),a.isVisible=!1,e&&(n=e.type,t="online"===e.agentStatus?u.AgentStatus.ONLINE:u.AgentStatus.OFFLINE),a.onChatClosedListener(a.chatCampaign,{agentStatus:t,chatType:n})},a.minimizeSnapEngageIframe=function(e){var t=e?Math.max(e.width,80):80,n=e?Math.max(e.height,80):80;a.iframe&&a.isVisible&&(a.iframe.style.width=t+"px",a.iframe.style.height=n+"px")},a.maximizeSnapEngageIframe=function(e){if(a.iframe){var t=(e||{}).width,n=(e||{}).height;a.iframe.style.width=t?t+"px":"",a.iframe.style.height=n?n+"px":""}},a.checkChatStatus=function(){a.sendMessage("checkChatStatusV2")},a.onOpenProactive=function(){a.onProviderDrivenOpenProactiveListener(a.chatCampaign)},a.onAgentStatusUpdate=function(e){a.onAgentStatusUpdateListener(a.chatCampaign,e)},a.isValidSource=function(e){return e.origin===a.metadata.snapengageIframeOrigin},a.onOpen=function(){a.onChatShownListener(a.chatCampaign)},a.onChatMessageReceived=function(){},a.onStartChat=function(){a.onChatStartedListener(a.chatCampaign)},a.onSwitchCampaign=function(){a.onSwitchCampaignListener(a.chatCampaign)},a.onSnapEngageInitialized=function(){a._isLoaded=!0,a.onChatLoadListener(a.chatCampaign,!0)},a.buildChatData=function(){var e=c.getSnapengageTags(a.userProperties.locale,a.userProperties.countryCode),t=n.isCampaignResult(a.chatCampaign)&&void 0!==a.chatCampaign.proactiveSettings&&null!==a.chatCampaign.proactiveSettings&&a.chatCampaign.proactiveSettings.whenToShowControlledByProvider;return{FirstName:a.userProperties.firstName,LastName:a.userProperties.lastName,Email:a.userProperties.email,SessionID:a.userProperties.sessionId,Country:a.userProperties.countryCode,pricing:a.userProperties.pricings.join(),user_id:a.userProperties.userId,pageLoadTs:a.userProperties.pageLoadTs,chatHmac:a.userProperties.chatHmac,ncct:"",serviceTier:a.userProperties.serviceTier,tags:e,phoneSupportForPlusUsers:a.userProperties.experiments.phoneSupportForPlusUsers,supportExperimentShowOnboardingNumber:a.userProperties.experiments.supportExperimentShowOnboardingNumber,supportExperimentHideEmailOption:a.userProperties.experiments.supportExperimentHideEmailOption,supportExperimentBasic36HourSla:a.userProperties.experiments.supportExperimentBasic36HourSla,phoneSupportForProfessionalUsers:a.userProperties.experiments.phoneSupportForProfessionalUsers,supportExperimentProfessionalPhoneSupportedLanguages:a.userProperties.experiments.supportExperimentProfessionalPhoneSupportedLanguages,cxChatbotName:"",allowProactive:t}},a.receiveMessage=function(e){a.isValidSource(e)&&("SnapEngageInitialized"===e.data.message_type?a.onSnapEngageInitialized():"UpdateChatStatus"===e.data.message_type?a.onAgentStatusUpdate(e.data.online):"Close"===e.data.message_type?a.onCloseChat(e.data):"Minimize"===e.data.message_type?a.minimizeSnapEngageIframe(e.data.rect):"Maximize"===e.data.message_type?a.maximizeSnapEngageIframe(e.data.rect):"OpenProactive"===e.data.message_type?a.onOpenProactive():"StartChat"===e.data.message_type?a.onStartChat():"onOpen"===e.data.message_type?a.onOpen():"EndProactiveChat"===e.data.message_type?a.onCloseChat():"ChatMessageReceived"===e.data.message_type?a.onChatMessageReceived():"onSwitchCampaign"===e.data.message_type&&a.onSwitchCampaign())},a.sendMessage=function(e){var t={message_type:e,chatId:a.chatId,chatData:a.chatData};a.iframe&&a.iframe.contentWindow&&a.iframe.contentWindow.postMessage(t,a.metadata.snapengageIframeOrigin)},a._isLoaded=!1,a.chatCampaign=t.campaignResult,a.metadata=t.metadata,a.userProperties=t.userProperties,a.onAgentStatusUpdateListener=t.onAgentStatusUpdate,a.onChatLoadListener=t.onChatLoadStatusUpdate,a.onChatShownListener=t.onChatShown,a.onChatStartedListener=t.onChatStarted,a.onChatClosedListener=t.onChatClosed,a.onSwitchCampaignListener=t.onSwitchCampaign,a.onProviderDrivenOpenProactiveListener=t.onProviderDrivenOpenProactive,a.isVisible=!1,a.iframeId="snapengage-iframe",a.chatData=a.buildChatData(),a.chatId=n.getSnapengageWidgetId(a.chatCampaign),a.initialize(),a}return a.__extends(t,e),t})(p.SnapengageChatInstanceHandler);t.SnapengageChatHandlerImpl=d})),define("modules/clean/chat/snapengage_chat_instance_handler_api",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var a=function(e){};t.SnapengageChatInstanceHandler=a})),define("modules/clean/chat/snapengage_chat_provider",["require","exports","tslib","modules/clean/chat/chat_identifier","modules/clean/chat/chat_provider_api","modules/clean/chat/snapengage_chat_instance_handler"],(function(e,t,a,n,i,r){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var o=(function(e){function t(t){var a=e.call(this,t)||this;return a.DEFAULT_WIDGET_ID="d5c1efed-d0ef-4fca-8c7d-faff398ad272",a.getDefaultChatIdentifier=function(){return a.DEFAULT_WIDGET_ID},a.loadChatIfNecessary=function(e){n.areChatCampaignsEqual(a.currentChatCampaign,e)?a.handler.isLoaded()&&a.onChatLoadStatusUpdate(a.currentChatCampaign,!0):a.handler.switchCampaign(e)},a.onSwitchCampaign=function(e){var t=a.currentChatCampaign;a.currentChatCampaign=e,a.onChatLoadStatusUpdate(t,!1),a.onAgentStatusUpdateListener(t,i.AgentStatus.NOT_SET),a.onChatLoadStatusUpdate(e,!0),a.handler.requestAgentStatusUpdate()},a.requestAgentStatusUpdate=function(e){if(!n.areChatCampaignsEqual(a.currentChatCampaign,e))throw new Error("Requesting agent status for a chat campaign that is not loaded");a.handler.requestAgentStatusUpdate()},a.showProviderReactiveChatButton=function(){a.handler.showReactiveButton()},a.startChat=function(e){if(!n.areChatCampaignsEqual(a.currentChatCampaign,e))throw new Error("Requesting to start chat for a chat campaign that is not loaded");a.handler.startChat()},a.updateHmac=function(){a.handler.updateHmac()},a.onAgentStatusUpdate=function(e,t){a.onAgentStatusUpdateListener(e,t?i.AgentStatus.ONLINE:i.AgentStatus.OFFLINE)},a.onAgentStatusUpdateListener=t.onAgentStatusUpdate,a.onChatLoadStatusUpdate=t.onChatLoadStatusUpdate,a.onChatShown=t.onChatShown,a.onChatStarted=t.onChatStarted,a.onChatClosed=t.onChatClosed,a.onProviderDrivenOpenProactive=t.onProviderDrivenOpenProactive,a.onProviderReactiveButtonShown=t.onProviderReactiveButtonShown,a.metadata=t.metadata,a.userProperties=t.userProperties,t.chatCampaign?(a.currentChatCampaign=t.chatCampaign,a.handler=a.createHandler(t.chatCampaign)):(a.currentChatCampaign=a.DEFAULT_WIDGET_ID,a.handler=a.createHandler(a.DEFAULT_WIDGET_ID)),a}return a.__extends(t,e),t.prototype.createHandler=function(e){return new r.SnapengageChatHandlerImpl({campaignResult:e,metadata:this.metadata,userProperties:this.userProperties,onAgentStatusUpdate:this.onAgentStatusUpdate,onChatLoadStatusUpdate:this.onChatLoadStatusUpdate,onChatShown:this.onChatShown,onChatStarted:this.onChatStarted,onChatClosed:this.onChatClosed,onProviderDrivenOpenProactive:this.onProviderDrivenOpenProactive,onProviderReactiveButtonShown:this.onProviderReactiveButtonShown,onSwitchCampaign:this.onSwitchCampaign})},t})(i.ChatProvider);t.SnapengageChatProvider=o})),define("modules/clean/chat/snapengage_tags",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var a={NAMER:["US","CA"],APAC:["AU","BD","KH","C2","FJ","GU","HK","IN","ID","JP","MY","MV","NP","NZ","PK","PH","SG","KR","LK","TW","TH","VN"],EMEA:["AL","DZ","AO","AT","AZ","BH","BY","BE","BA","BW","BG","CM","HR","CY","CZ","DK","EG","EE","ET","FI","FR","GE","DE","GH","GI","GR","HU","IS","IQ","IE","IL","IT","CI","JO","KE","KW","LV","LB","LT","LU","MK","MG","MT","MQ","MU","MD","MC","MA","MZ","NA","NL","NG","NO","OM","PS","PL","PT","QA","RO","RU","RW","SA","SN","RS","SK","SI","ZA","ES","SE","CH","TZ","TN","TR","UG","UA","AE","GB","YE","ZM","ZW"],LATAM:["AG","AN","AR","AW","BB","BO","BR","BS","BZ","CL","CO","CR","CU","DM","DO","EC","GT","GY","HN","HT","JM","KN","LC","MX","NI","PA","PE","PR","PY","SR","SV","TT","UY","VC","VE"]},n={en:"",en_GB:"",da_DK:"dutch",de:"german",es:"spanish, spanish-la",es_ES:"spanish, spanish-es",fr:"french",id:"",it:"italian",ja:"japanese",ko:"korean",ms:"",nb_NO:"norwegian",nl_NL:"dutch",pl:"",pt_BR:"portuguese",ru:"russian",sv_SE:"swedish",th_TH:"thai",zh_CN:"chinese, chinese-sim",zh_TW:"chinese, chinese-trad"};t.getSnapengageTags=function(e,t){var a=[],r=n[e],o=i(t);return void 0!==r&&a.push(r),void 0!==o&&a.push(o),a.join(", ")};var i=function(e){if(void 0!==e)return a.NAMER.indexOf(e)>=0?"namer":a.APAC.indexOf(e)>=0?"apac":a.EMEA.indexOf(e)>=0?"emea":a.LATAM.indexOf(e)>=0?"latam":void 0}}));
//# sourceMappingURL=pkg-chat.min.js-vflZmzjga.map