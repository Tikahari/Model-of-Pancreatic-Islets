define(["require","exports","tslib","react","modules/clean/ajax","classnames","jquery","modules/core/i18n","spectrum/button","modules/clean/react/css","modules/clean/react/prompt/prompt_location","modules/clean/react/prompt/image","modules/clean/react/prompt/button","modules/clean/top_notification_bar","modules/clean/static_urls","modules/clean/react/sprite","modules/clean/upsell/upsell_controller","modules/clean/react/maestro/components/header_portal"],(function(t,e,n,o,i,a,s,r,l,c,u,p,m,f,d,_,g,h){"use strict";var b;Object.defineProperty(e,"__esModule",{value:!0}),o=n.__importDefault(o),i=n.__importStar(i),a=n.__importDefault(a),s=n.__importDefault(s),g=n.__importDefault(g),(function(t){t[t.HelpPinCode=3]="HelpPinCode"})(b||(b={}));var C=(function(t){function e(){var e=null!==t&&t.apply(this,arguments)||this;return e.handleOnConfirm=function(){e.onConfirm()},e.handleOnDismiss=function(){e.onDismiss(),e.setState({isDismissed:!0})},e.getBarType=function(){var t=e.props.campaign.content;return t?t.style:"info"},e.getNotificationContent=function(){var t=e.props.campaign.content,n=void 0,i=t.confirmInNewTab?"_blank":"_self",a=t.buttonUrl?t.buttonUrl:"#";return t.buttonText&&(n=o.default.createElement("a",{className:"top-notification-link-button freshbutton-blue",href:a,target:i,onClick:e.state_manager.onConfirm},t.buttonText)),o.default.createElement(o.default.Fragment,null,o.default.createElement("span",{className:"top-notification-bar__text",dangerouslySetInnerHTML:m.sanitizeOptionalHTML(t.text),ref:e.enhanceInlineTextButtons}),n,e.getDismissButton())},e.enhanceInlineTextButtons=function(t){if(t){var o=s.default(t).find("a:not(.dismiss-button)"),i=s.default(t).find(".dismiss-button");e.props.campaign.content.confirmInNewTab&&o.attr("target","_blank"),new g.default(o,i,n.__assign(n.__assign(n.__assign({},e.props),e.props.campaign),e.props.campaign.content)),g.default.register_custom_controller({on_confirm:e.handleOnConfirm,on_dismiss:e.handleOnDismiss})}},e.getDismissButton=function(){var t=null;if(e.props.campaign.content.notDismissable)return null;t="black"!==e.getBarType()?o.default.createElement(_.Sprite,{group:"web",name:"banner_x",alt:r.intl.formatMessage({id:"v4qAYu",defaultMessage:"Close"})}):o.default.createElement(p.Image,{src:d.static_url("/static/images/top-notification-x-white-vflCh9Pt1.svg"),alt:r.intl.formatMessage({id:"v4qAYu",defaultMessage:"Close"})});return o.default.createElement(l.Button,{variant:"styleless",className:"top-notification-bar-dismiss dismiss-button",onClick:function(t){e.props.campaign.content.modalType===b.HelpPinCode&&i.SilentBackgroundRequest({url:"/team/invalidate_pin"}),e.onDismiss(),e.state_manager.onDismiss(t)}},t)},e}return n.__extends(e,t),e.prototype.componentDidMount=function(){this.state_manager.onShow(),this.onShow()},e.prototype.componentWillUnmount=function(){g.default.unregister_custom_controller({on_confirm:this.handleOnConfirm,on_dismiss:this.handleOnDismiss})},e.prototype.onShow=function(){s.default("#notify-wrapper").addClass("with-top-notification"),s.default(".maestro body").addClass("has-top-notification")},e.prototype.onConfirm=function(){this.setState({isConfirmed:!0})},e.prototype.onDismiss=function(){f.removeClassIfElmExists(".maestro .has-top-notification","has-top-notification"),f.removeClassIfElmExists(".maestro #notify-wrapper.with-top-notification","with-top-notification")},e.prototype.getNotification=function(){var t=a.default({"top-notification-bar":!0,"top-notification-bar-with-button":!!this.props.campaign.content.buttonText});return o.default.createElement("div",{id:"prompt-top-notification-bar",className:t},this.getNotificationContent())},e.prototype.render=function(){if(!this.props.campaign.content)return null;if(this.state.isConfirmed||this.state.isDismissed)return null;var t=this.getBarType(),e="";return e="warning"===t?"lightyellow":"info"===t?"lightblue":"black"===t?"black":"lightred",o.default.createElement(h.MaestroPortal,{maestroPortalExperiment:this.props.useMaestroPortal,element:h.MaestroPortalElement.PROMPT},o.default.createElement("div",{id:"top-notification-bar-container",className:"top-notification-bar-container "+e,tabIndex:0},this.getNotification()))},e.displayName="TopNotificationWithoutCSS",e})(u.PromptLocationWithDefaultState);e.TopNotificationRendererWithoutCSS=C,e.TopNotification=c.requireCssWithComponent(C,["/static/css/upsell/prompt_pagelet-vflDBfMJR.css"]),e.WrappedTopNotification=function(t){return o.default.createElement("div",{className:"top-notification-bar-silo"},o.default.createElement(e.TopNotification,n.__assign({},t)))}}));
//# sourceMappingURL=top_notification.min.js-vflmik372.map