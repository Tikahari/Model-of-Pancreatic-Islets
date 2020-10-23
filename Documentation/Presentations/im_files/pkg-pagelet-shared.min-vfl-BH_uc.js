define("modules/clean/components/loading_indicator",["require","exports","tslib","classnames","react","react-dom-factories","prop-types","external/lodash","modules/core/accessible_announce","modules/core/i18n"],(function(e,t,n,r,i,a,o,s,l,u){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=n.__importDefault(r),i=n.__importDefault(i),a=n.__importDefault(a),o=n.__importStar(o),s=n.__importStar(s),t.LoadingIndicatorStyle={DOTS:"dots",SPINNER:"spinner",BLUE_SPINNER:"blue_spinner"};var d=(function(e){function i(){return null!==e&&e.apply(this,arguments)||this}return n.__extends(i,e),i.prototype.componentDidMount=function(){this.props.shouldAnnounceMessage&&l.AccessibleAnnounce.polite(this.props.startMessage)},i.prototype.componentWillUnmount=function(){this.props.finishMessage&&this.props.shouldAnnounceMessage&&l.AccessibleAnnounce.polite(this.props.finishMessage)},i.prototype.render=function(){var e={};if(this.props.className){var i=this.props.className.split(" ");e=s.zipObject(i,i.map((function(e){return!0})))}return e=n.__assign(n.__assign({},e),{"c-loader":!0,"c-loader--spinner":this.props.style===t.LoadingIndicatorStyle.SPINNER,"c-loader--spinner--blue":this.props.style===t.LoadingIndicatorStyle.BLUE_SPINNER}),a.default.div({className:r.default(e)},this.props.startMessage)},i.displayName="LoadingIndicator",i.LoadingIndicatorStyle=t.LoadingIndicatorStyle,i.propTypes={style:o.oneOf(s.values(t.LoadingIndicatorStyle)),className:o.string,startMessage:o.string,finishMessage:o.string,shouldAnnounceMessage:o.bool},i.defaultProps={style:t.LoadingIndicatorStyle.DOTS,className:"",startMessage:u.intl.formatMessage({id:"M85BdF",defaultMessage:"Loading…"}),finishMessage:null,shouldAnnounceMessage:!0},i})(i.default.Component);t.LoadingIndicator=d})),define("modules/clean/photos/thumbnail_url_util",["require","exports","tslib","external/lodash","modules/constants/python","modules/core/exception","modules/core/uri"],(function(e,t,n,r,i,a,o){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=n.__importStar(r),i=n.__importStar(i),a=n.__importStar(a),t.ThumbnailSizeMode=i.THUMBNAIL_SIZE_MODE;var s=i.THUMBNAIL_SIZES;t.thumbnailUrlForSize=function(e,n,i,l){a.assert(null!=n==(null!=i),"Width and height must both be specified or neither");var u={};if(null==n)a.assert(l===t.ThumbnailSizeMode.ORIGINAL||null===l,"You must supply width and height");else{var d=n+"x"+i;a.assert(s.indexOf(d)>-1,"Invalid thumbnail size ("+d+")"),u.size=d}return null!=l&&(a.assert(r.values(t.ThumbnailSizeMode).indexOf(l)>-1,"Invalid thumbnail size mode ("+l+")"),u.size_mode=l.toString()),o.URI.parse(e).updateQuery(u).toString()},t.fullSizeUrl=function(e){return o.URI.parse(e).updateQuery({size_mode:t.ThumbnailSizeMode.ORIGINAL.toString(),fv_content:"true"}).toString()}}));var __importStar=this&&this.__importStar||function(e){if(e&&e.__esModule)return e;var t={};if(null!=e)for(var n in e)Object.hasOwnProperty.call(e,n)&&(t[n]=e[n]);return t.default=e,t};define("modules/clean/sharing/async_share_modal_util",["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.asyncShowNewFolderShareModal=function(t,n,r,i,a,o,s,l,u,d,h,p,c,m,f,_,g){void 0===n&&(n=null),void 0===r&&(r=null),void 0===i&&(i=null),void 0===a&&(a=!1),void 0===o&&(o=!1),void 0===s&&(s=null),void 0===p&&(p=null),void 0===c&&(c=null),new Promise((function(t,n){e(["modules/clean/sharing/share_modal_util"],t,n)})).then(__importStar).then((function(e){return e.showNewFolderShareModal(t,n,r,i,a,o,s,l,u,d,h,p,c,m,f,_,g)}))},t.asyncShowShareModal=function(t,n,r,i,a){return void 0===r&&(r={}),new Promise((function(o){new Promise((function(t,n){e(["modules/clean/sharing/share_modal_util"],t,n)})).then(__importStar).then((function(e){o(e.showShareModal(t,n,r,i,a))}))}))},t.asyncShowPrefilledShareModal=function(t){var n=t.user,r=t.sharePrefillEmails,i=t.content,a=t.setUrl,o=t.contentManagerValidateFolderPath,s=t.extras;new Promise((function(t,n){e(["modules/clean/sharing/share_modal_util"],t,n)})).then(__importStar).then((function(e){e.showPrefilledShareModal({user:n,sharePrefillEmails:r,content:i,setUrl:a,contentManagerValidateFolderPath:o,extras:s})}))}})),define("modules/clean/react/file_path_breadcrumb",["require","exports","tslib","classnames","react","external/lodash","modules/clean/react/title_bubble","modules/clean/em_string"],(function(e,t,n,r,i,a,o,s){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=n.__importDefault(r),i=n.__importDefault(i),a=n.__importStar(a);var l=function(e){return Math.floor(1e3*e)},u=function(e){return e/1e3};function d(e){var t=new s.Emstring(e.name).length;return{name:e.name,href:e.url,width:t,workingWidth:l(t)}}var h=(function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.handlePathClick=function(e){t.props.handlePathClick(e)},t}return n.__extends(t,e),t.prototype.getTotalPathWidth=function(e){for(var t=0,n=l(this.props.pathDividerWidth),r=0;r<e.length;r++){t+=e[r].workingWidth,r<e.length-1&&(t+=n)}return t},t.prototype.getPathsAvailable=function(){var e=this.props.paths;return e.length>1?e.slice(1):e},t.prototype.getPathsToShow=function(){for(var e=l(this.props.minPathWidth),t=l(this.props.pathDividerWidth),r=l(this.props.maxWidth),i=this.getPathsAvailable(),o=i.map(d),s=0,h=0;this.getTotalPathWidth(o)>r;){if(h++>100)return S();if(s+3<=i.length){var p=[o[0],d({name:this.props.morePathsString})],c=0===s?2:3,m=o.slice(c,o.length);o=n.__spreadArrays(p,m),s++}else{if(1===o.length)return S();for(var f=r,_=0;_<o.length-1;_++){f-=o[_].workingWidth+t}if(f<e)return S();var g=a.last(o);g.width=u(f),g.workingWidth=f}}return o;function S(){var e=a.last(o);return e.width=u(r),e.workingWidth=r,[e]}},t.prototype.render=function(){var e=this,t=this.props.pathClassname,n=this.props,a=n.morePathsString,l=n.useLinks,u=!1,d=this.getPathsToShow().map((function(n){var o=n.name,d=n.width,h=n.href;u=u||o===a;var p=s.Emstring.em_snippet(o,d),c=[t];return h&&l?(c.push(t+"--level"),i.default.createElement("a",{href:h,className:r.default(c),onClick:e.handlePathClick},p)):(c.push(t+"--more"),i.default.createElement("span",{className:r.default(c)},p))})),h=i.default.createElement("span",{className:t+"--wrapper"},d);return u&&this.props.showTooltipOnTruncated?i.default.createElement(o.TitleBubble,{content:this.getPathsAvailable().map((function(e){return e.name})).join(" > "),position:o.TitleBubble.POSITIONS.TOP,isTargetPositionFixed:!0},h):h},t.defaultProps={pathClassname:"file-path-breadcrumb-component",maxWidth:46,minPathWidth:3,morePathsString:"…",pathDividerWidth:1.077,handlePathClick:a.noop,useLinks:!0,showTooltipOnTruncated:!1},t})(i.default.Component);t.FilePathBreadcrumb=h}));
//# sourceMappingURL=pkg-pagelet-shared.min.js-vflg19twv.map