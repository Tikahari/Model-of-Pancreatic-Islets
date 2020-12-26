define("modules/clean/auth_event_logger",["require","exports","tslib","modules/clean/api_v2/noauth_client","modules/core/browser"],(function(e,t,a,n,o){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),o=a.__importStar(o),t.AuthEventLogger={log_web_login_intent:function(){i({".tag":"web_login_intent"})},log_web_signup_intent:function(){i({".tag":"web_signup_intent"})},log_web_login_captcha:function(){i({".tag":"web_login_captcha"})},log_web_signup_captcha:function(){i({".tag":"web_signup_captcha"})}};var i=function(e){(new n.NoAuthApiV2Client).ns("auth_logger").rpc("log_auth_event",{event_name:e,event_url:o.get_href()},{})}})),define("modules/clean/react/paper/paper_log",["require","exports","tslib","modules/clean/ajax","modules/core/browser"],(function(e,t,a,n,o){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),n=a.__importStar(n),o=a.__importStar(o),t.PaperEventTypes={VIDEO_PLAY:"main_video_play",VIDEO_PERCENT_PLAYED:"main_video_percent_played",CLICK:"click",CTA_CLICK:"cta_click",CTA_SEEN:"cta_seen",AUTH:"auth",FAQ_INTERACTION:"faq-interaction",IOS_BUTTON_CLICK:"ios_button_click",ANDROID_BUTTON_CLICK:"android_button_click",ROTATOR_NEXT_CLICK:"rotator_next_click",ROTATOR_PREVIOUS_CLICK:"rotator_previous_click",ROTATOR_DOT_CLICK:"rotator_dot_click",BALLET_VIDEO_PLAY:"ballet_video_play",LES_LUNES_VIDEO_PLAY:"les_lunes_video_play",LONELY_PLANET_VIDEO_PLAY:"lonely_planet_video_play"},t.paperLog=function(e,t,i,_){void 0===t&&(t={}),void 0===_&&(_={}),t.pathname=o.get_pathname(),i?n.SilentBackgroundRequest(a.__assign({url:"/log/paper",data:{event_type:e,extra_params:JSON.stringify(t)},success:i,error:i},_)):n.SilentBackgroundBeaconRequest(a.__assign({url:"/log/paper",data:{event_type:e,extra_params:JSON.stringify(t)}},_))}})),define("modules/clean/react/flag",["require","exports","tslib","classnames","react","react-dom-factories","prop-types","modules/clean/react/css"],(function(e,t,a,n,o,i,_,r){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),n=a.__importDefault(n),o=a.__importDefault(o),i=a.__importDefault(i),_=a.__importStar(_);var s=(function(e){function t(){return null!==e&&e.apply(this,arguments)||this}return a.__extends(t,e),t.prototype.render=function(){var e,t,a=((e={"o-flag":!0})["o-flag--"+this.props.alignment]=this.props.alignment,e),o=((t={"o-flag__flex":!0})["u-pad-left-"+this.props.spacing]=this.props.spacing&&this.props.leftAttachment,t["u-pad-right-"+this.props.spacing]=this.props.spacing&&this.props.rightAttachment,t),_=this.props.leftAttachment?i.default.div({className:"o-flag__fix"},this.props.leftAttachment):void 0,r=this.props.rightAttachment?i.default.div({className:"o-flag__fix"},this.props.rightAttachment):void 0;return i.default.div({className:n.default(a)},_,i.default.div({className:n.default(o)},this.props.children),r)},t.displayName="Flag",t.propTypes={alignment:_.oneOf(["top","middle","bottom"]),leftAttachment:_.oneOfType([_.element,_.node]),rightAttachment:_.oneOfType([_.element,_.node]),spacing:_.oneOf(["xs","s","m","l","xl"]),children:_.oneOfType([_.element,_.node])},t.defaultProps={alignment:"middle"},t})(o.default.Component);t.FlagWithoutCss=s;var l=r.requireCssWithComponent(s,["/static/css/scooter/scooter-scoped-vfljL5ijS.css"]);t.Flag=l}));
//# sourceMappingURL=pkg-login-pages.min.js-vflD7drfD.map