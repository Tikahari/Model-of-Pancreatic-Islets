define(["require","exports","tslib","react","react-intl","modules/clean/react/css","spectrum/button","modules/core/i18n","modules/clean/react/app_actions/telemetry_client","modules/clean/filepath","modules/clean/react/extensions/status_page"],(function(e,t,a,n,s,r,i,o,l,c,u){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var p=(function(e){function t(t){var a=e.call(this,t)||this;return a.clickAuthorize=function(){a.currentSession.event("auth_accept",{action_id:a.props.actionId}),a.props.doAuth()},a.learnMoreOnClick=function(){a.currentSession.event("learn_more",{action_id:a.props.actionId}),a.props.onLearnMore&&a.props.onLearnMore()},a.telemetryClient=l.createTelemetryClient({component:"auth_v2"}),a}return a.__extends(t,e),t.prototype.componentDidMount=function(){this.currentSession.event("auth_start",{action_id:this.props.actionId})},t.prototype.renderText=function(){var e=0!==this.props.fileId.length?s.defineMessage({id:"VDSuu6",defaultMessage:"<b>{app_name}</b> needs access to this file"}):s.defineMessage({id:"mZo8K4",defaultMessage:"<b>{app_name}</b> needs access to files you select"}),t=0!==this.props.fileId.length?s.defineMessage({id:"hE6l1Q",defaultMessage:"Changes to this file using {app_name} will save back to Dropbox. This app will have access to the username, email address, and country for your account."}):s.defineMessage({id:"HsAedA",defaultMessage:"Changes to selected files using {app_name} will save back to Dropbox. This app will have access to the username, email address, and country for your account."});return n.default.createElement("div",null,n.default.createElement("div",{className:"auth-text-header-v2"},o.intl.formatMessage(e,{app_name:this.props.appName,b:function(e){return n.default.createElement("b",null,e)}})),n.default.createElement("div",{className:"auth-text-v2"},o.intl.formatMessage(t,{app_name:this.props.appName}),n.default.createElement("a",{className:"learn-more-link",href:"/help/security/third-party-apps",target:"_blank",rel:"noopener noreferrer",onClick:this.learnMoreOnClick},o.intl.formatMessage({id:"gk12sS",defaultMessage:"Learn more"}))))},t.prototype.renderButtons=function(){return n.default.createElement("div",null,n.default.createElement(i.Button,{variant:"primary",className:"auth-button-v2",onClick:this.clickAuthorize},o.intl.formatMessage({id:"LGeX5c",defaultMessage:"Allow"})))},t.prototype.renderAuthorization=function(){var e=this.props,t=e.appName,a=e.iconUrl;return n.default.createElement("div",{id:"auth",className:"auth-connect-frame-v2"},n.default.createElement("div",null,n.default.createElement("img",{className:"app-icon-v2",src:a,alt:t})),n.default.createElement("div",null,this.renderText()),n.default.createElement("div",{id:"buttons"},this.renderButtons()))},t.prototype.render=function(){var e=this.props.fileName;return this.currentSession=this.telemetryClient.session({ext:l.getPiiSafeExtension("."+c.file_extension(e))}),this.props.showLoadingUI?n.default.createElement(u.AppActionsLoadingPage,{fileName:e}):this.renderAuthorization()},t})((n=a.__importDefault(n)).default.Component);t.ExtensionsAuthBodyV2=r.requireCssWithComponent(p,["/static/css/spectrum/index.web-vfl6Z83yw.css","/static/css/foundation-vflVWYClF.css","/static/css/app_actions/index-vflHsvf3d.css"])}));
//# sourceMappingURL=auth_body_v2.min.js-vflZXPKuW.map