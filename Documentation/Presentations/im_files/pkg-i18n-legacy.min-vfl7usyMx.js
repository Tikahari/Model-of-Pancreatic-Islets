define("modules/core/format_html",["require","exports","tslib","react-intl","modules/core/exception","modules/constants/page_load","modules/core/i18n"],(function(e,t,r,o,a,n,s){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),n=r.__importStar(n);var c=s.localeToBcp47LangTag(n.USER_LOCALE),l=o.createIntl({messages:{},locale:c,onError:function(e){if(e.code!==o.ReactIntlErrorCode.MISSING_TRANSLATION)return a.reportException({err:e,tags:["format_html"],severity:a.SEVERITY.CRITICAL})}});t.legacyFormatHtmlAsReact=function(e,t){return l.formatMessage({id:e,defaultMessage:e,description:"nothing"},t)}}));
//# sourceMappingURL=pkg-i18n-legacy.min.js-vfl6r1wQC.map